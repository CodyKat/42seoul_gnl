#include "get_next_line.h"
#define BUFFER_SIZE 1
#define FD_MAX 5 
#define POP 0
#define PUSH 1
#define NONE -1
#define NORMAL 1
#define NEWLINE 2
#define END_EOF 0
#define HEAD -1
#define EMPTY -2

void    free_all(t_node **table)
{
    int index;
    t_node  *front;
    t_node  *rear;

    index = -1;
    while (++index < FD_MAX)
    {
        front = table[index]->next;
        rear = front;
        while (front)
        {
            front = front->next;
            if (rear->text != 0)
                free(rear->text);
            free(rear);
            rear = front;
        }
    }
    //while (--index >= 0)
    //{
    //   free(table[index]);
    //    free(table[index + FD_MAX]);
    //    index++;
    //}
    free(table);
}

int push_pop(t_node **head, int fd, int mode) // malloc fail -> return 0
{
    t_node  *new_node;

    if (mode == POP)
    {
        *head = (*head)->next;
        free((*head)->prev->text);
        free((*head)->prev);
        (*head)->prev = *head;
        return (1);
    }
    new_node = (t_node *)ft_calloc(1, sizeof(t_node));
    if (new_node == 0)
        return (0);
    (*head)->next = new_node;
    new_node->prev = *head;
    *head = new_node;
    new_node->text = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (new_node->text == 0)
        return (0);
    new_node->node_len = read(fd, new_node->text, BUFFER_SIZE);
    if (new_node->node_len == -1)
        return (0);
    (*head)->oneline_len += ft_cal_oneline(new_node->text);
    return (1);
}

t_node  **init_table(char **line)
{
    t_node  **table;
    int     index;

    table = (t_node **)ft_calloc(sizeof(t_node *),  FD_MAX * 2);
    if (table == 0)
        return (0);
    index = -1;
    while (++index < FD_MAX)
    {
        table[index] = (t_node *)ft_calloc(1, sizeof(t_node));
        if (table[index] == 0)
        {
            while (--index >= 0)
                free(table[index]);
            free(table);
            return (0);
        }
        table[index]->status = HEAD;
        table[index]->oneline_len = 0;
        table[index + FD_MAX] = table[index];
    }
    *line = 0;
    return (table);
}

char    *get_oneline(t_node *head)
{
    t_node  *node;
    char    *line;
    int     count;

    line = (char *)malloc(sizeof(char) * (head->oneline_len) + 1);
    if (line == 0)
        return (0);
    count = 0;
    node = head->next;
    while (node->status == NORMAL)
    {
        if (node->node_len == BUFFER_SIZE)
            ft_memcpy(line + count * BUFFER_SIZE, node->text, BUFFER_SIZE);
        else
            ft_memcpy(line + count * BUFFER_SIZE, node->text, node->node_len);
        push_pop(&head, NONE, POP);
        count++;
    }
    if (node->status == NEWLINE)
    {
        if (node->cursor == 0)
            node->cursor = node->text;
        ft_memcpy(line + count * BUFFER_SIZE, node->cursor, ft_cal_oneline(node->cursor) + 1);
        node->cursor += ft_cal_oneline(node->cursor);
    }
    return (line);
}
char    *get_next_line(int fd)
{
    static t_node   **table;
    char            *line;
    t_node          last_node;
    
    table = init_table(&line);
    if (table == 0)
        return (0);
    last_node = *table[fd + FD_MAX];
    while (1)
    {
        if (last_node.status == NORMAL || last_node.status == HEAD)
            if (push_pop(&table[fd + FD_MAX], fd, PUSH) == 0)
                break;
        else if (last_node.status == END_EOF || last_node.status == NEWLINE)
        {
            line = get_oneline(table[fd]);
            break;
        }
        else if (last_node.status == EMPTY)
            push_pop(&table[fd], NONE, POP);
    }
    if (line == 0)
        free_all(table);
    return (line);
}

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c		\
	   get_next_line_utils.c
SRCS_BONUS = 
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

ifdef IS_BONUS
	OBJ_FILES = ${OBJS} ${OBJS_BONUS}
else
	OBJ_FILES = ${OBJS}
endif

all : ${NAME}

$(NAME) : ${OBJ_FILES}
	ar rs ${NAME} ${OBJ_FILES}

clean :
	rm -f ${OBJS} ${OBJS_BONUS}

fclean : clean
	rm -f ${NAME}

bonus :
	IS_BONUS=1 make all

.PHONY : all clean fclean bonus re

re : fclean all

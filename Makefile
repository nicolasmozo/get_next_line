NAME = libft.a
SOURCE = srcs/

SRCS =	get_next_line.c\

OBJS = ${SRCS:.c=.o}
INCLUDES = libft.h
COMPILE_FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
.c.o:
		${CC} ${COMPILE_FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${INCLUDES}
		ar rc ${NAME} ${OBJS}
all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all
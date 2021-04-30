SRCS	=	libft/ft_isdigit.c libft/ft_itoa.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strlen.c libft/ft_strdup.c srcs/ft_print3.c srcs/convert_base.c srcs/ft_print.c srcs/ft_print2.c srcs/itoas.c srcs/sort.c ft_printf.c

CC		= gcc

INCLUDE	= ./include/libftprintf.h

NAME	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

OBJS	= ${SRCS:.c=.o}

LIB		= ar rc

.c.o:
			${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${LIB} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus

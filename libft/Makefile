SRCS	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_memcpy.c ft_strjoin.c ft_strdup.c ft_strlcat.c

BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstclear.c

OBJS_B	= ${BONUS:.c=.o}

CC		= gcc

INCLUDE	= ./

NAME	= libft.a

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

OBJS	= ${SRCS:.c=.o}

LIB		= ar rc

.c.o:
			${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${LIB} ${NAME} ${OBJS}

all:		${NAME}

bonus:		${OBJS_B}
			${LIB} ${NAME} ${OBJS_B}

clean:
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus

NAME 	= libft.a
SRCS 	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
ft_toupper.c ft_strchr.c
SRCSBONUS = ${OBJS} ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstadd_back.c ft_lstlast.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_lstprint.c
HEADER 	= Includes
CC 		= gcc -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}
OBJSBONUS = ${SRCSBONUS:.c=.o}

.c.o:
	gcc -I ${HEADER} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

bonus : ${OBJSBONUS}
	ar rc ${NAME} ${OBJSBONUS}
	ranlib ${NAME}	

clean :
	rm -f ${OBJSBONUS} 

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY: re fclean all clean

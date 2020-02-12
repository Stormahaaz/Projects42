NAME 	= libftprintf.a
LIBFT	= libft
SRCS 	= srcs
HEADER 	= Includes
CC 		= gcc -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}

.c.o:
	${CC} -I ${HEADER} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@make -C ${LIBFT}
	@cp libft/libft.a ./${NAME}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}

clean :
	rm -f ${OBJS} 

fclean :
	rm -rf ${NAME}

re : fclean all

.PHONY: re fclean all clean

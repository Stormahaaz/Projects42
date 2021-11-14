NAME 	= push_swap
PRINTF  = ./printf
SRCS 	= ./srcs/stacks_tools/ft_build_stacks.c \
push_swap.c \
./srcs/stacks_op/ft_stacks_op.c \
./srcs/stacks_tools/ft_lstft_review.c \
./srcs/stacks_tools/ft_get_stacks_info.c

HEADER 	= include
CC 		= gcc -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}

.c.o:
	${CC} -I ${HEADER} -c $< -o ${<:.c=.o}

all : ${NAME}

bonus : ${NAME}

${NAME} : ${OBJS}
	${MAKE} -C ${PRINTF}
	cp ${PRINTF}/libftprintf.a .
	${CC} ${OBJS} libftprintf.a -o ${NAME}

clean :
	make clean -C ${PRINTF}
	rm -f ${OBJS} 

fclean : clean
	make fclean -C ${PRINTF}
	rm -rf ${NAME}

re : fclean all

.PHONY: re fclean all clean

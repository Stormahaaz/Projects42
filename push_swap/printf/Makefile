NAME 	= libftprintf.a
LIBFT	= ./libft
SRCS 	= ft_printf.c \
./srcs/convs/ft_apply_conv.c \
./srcs/convs/ft_print_hex.c \
./srcs/convs/ft_print_mem.c \
./srcs/convs/ft_printd_i.c \
./srcs/convs/ft_prints.c \
./srcs/utils/ft_numlen.c \
./srcs/utils/ft_print_width.c \
./srcs/utils/ft_putchar_pf.c \
./srcs/utils/ft_stock_flags.c \
./srcs/utils/ft_strdupn.c 

HEADER 	= include
CC 		= gcc -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}

.c.o:
	${CC} -I ${HEADER} -c $< -o ${<:.c=.o}

all : ${NAME}

bonus : ${NAME}

${NAME} : ${OBJS}
	${MAKE} bonus -C ${LIBFT}
	cp libft/libft.a ./${NAME}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean :
	make clean -C ${LIBFT}
	rm -f ${OBJS} 

fclean : clean
	make fclean -C ${LIBFT}
	rm -rf ${NAME}

re : fclean all

.PHONY: re fclean all clean

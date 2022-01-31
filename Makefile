NAME = libftprintf.a

SRCS = 	ft_printf_utils.c \
		ft_printf.c \
		ftp_char_utils.c \
		ftp_hex_utils.c \
		ftp_num_utils.c \
		ftp_ptr_utils.c \
		ftp_uint_utils.c \

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

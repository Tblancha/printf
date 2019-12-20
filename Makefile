NAME =		libftprintf.a

SRC =		convert_to_base.c \
			convert_va_arg_to_str.c \
			convert_va_arg_to_str2.c \
			ft_printf.c \
			parse_percent.c \
			write_to_buff.c \
			apply_flag_router.c \
			apply_precision.c \
			calcul_real_padding.c \
			diese_sign_correction_padding.c \
			dispatch_type.c \
			dispatch_type2.c \
			ignore_flag.c \
			ignore_flag2.c \

OBJ =		$(SRC:.c=.o)

HEADER =	ft_printf.h

FLAG =		-Wall -Werror -Wextra

LIBFT =		libft/libft.a

$(NAME) :	lib
			@gcc $(FLAG) -c $(SRC)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

all :		$(NAME)

lib :
			@make -C libft

clean :
			@/bin/rm -f $(OBJ)
			@make -C libft clean

fclean :	clean
			@/bin/rm -f $(NAME) ft_printf
			@make -C libft fclean

re : 		fclean all
			@make -C libft re

ssflag :
			@gcc -c $(SRC)
			@gcc $(LIBFT) $(OBJ) -o $(NAME)
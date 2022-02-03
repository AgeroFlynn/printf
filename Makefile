NAME	=	libftprintf.a

SRC		=	ft_printf.c	ft_printf_utils.c

OBJ		=	$(SRC:.c=.o)

HEADER	=	ft_printf.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

%.o:		%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re

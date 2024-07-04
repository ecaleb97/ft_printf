NAME	= libftprintf.a

SRCS	= ft_printf.c \
		ft_number.c \
		ft_string.c \
		ft_pointer.c \
		ft_hex.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): 	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

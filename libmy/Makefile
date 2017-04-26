NAME	=	libmy.a

SRC	=	my_putchar.c \
		my_isneg.c \
		my_put_nbr.c \
		my_swap.c \
		my_putstr.c \
		my_strlen.c \
		my_getnbr.c \
		my_aff_tab.c \
		my_strcpy.c \
		my_strncpy.c \
		my_strcmp.c \
		my_strncmp.c \
		my_strcat.c \
		my_strncat.c \
		my_strstr.c \
		my_putnbr_base.c \
		my_strdup.c \
		my_str_to_wordtab.c

OBJ	=	$(SRC:%.c=%.o)

AR	=	ar r

RANLIB	=	ranlib

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		$(RANLIB) $(NAME)

clean:		
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

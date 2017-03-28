CC =		gcc

RM =		rm -f

LIB =		cd libmy/; make

LIB_CLEAN =	cd libmy/; make clean

LIB_FCLEAN =	cd libmy/; make fclean

CFLAGS =	-Wall -Werror -W -Wextra

NAME_CLIENT =	client_bin

SRCS_CLIENT =	$(wildcard client/*.c)

OBJS_CLIENT =	$(SRCS_CLIENT:%.c=%.o)

all:		$(NAME_CLIENT)

client:		$(NAME_CLIENT)

$(NAME_CLIENT):	$(OBJS_CLIENT)
		@$(LIB)
		@echo "-> Compilation client_bin ..."
		$(CC) $(OBJS_CLIENT) -L libmy/ -lmy $(CFLAGS) -o $(NAME_CLIENT) $(LDFLAGS)

clean:		
		@echo "-> clean client..."
		@$(RM) $(OBJS_CLIENT)
		@$(LIB_CLEAN)

fclean:		clean
		@echo "-> fclean client..."
		@$(RM) $(NAME_CLIENT)
		@$(LIB_FCLEAN)

re:		fclean all clean

.PHONY:		all clean fclean re

CC =		gcc

RM =		rm -f

LIB =		cd libmy/; make

LIB_CLEAN =	cd libmy/; make clean

LIB_FCLEAN =	cd libmy/; make fclean

CFLAGS =	-Wall -Werror -W -Wextra

NAME_CLIENT =	client_bin

NAME_SERVER =   server_bin

SRCS_CLIENT =	client/bzero.c		\
		client/connect.c	\
		client/freetab.c	\
		client/get_cmd.c	\
		client/main.c		\
		client/my_client.c	\
		client/tablen.c

SRCS_SERVER =   server/main.c			\
		server/add_client.c		\
		server/add_elem.c		\
		server/change_chan.c		\
		server/check_user_in_chan.c	\
		server/client_read.c		\
		server/create_env.c		\
		server/create_node.c		\
		server/get_cmd.c		\
		server/get_current.c		\
		server/list.c			\
		server/move_node.c		\
		server/my_disconnect.c		\
		server/my_join.c		\
		server/my_putnbr_fd.c		\
		server/my_putstr_fd.c		\
		server/my_server.c		\
		server/send_msg_in_chan.c	\
		server/show_all_users.c		\
		server/tablen.c			\

OBJS_CLIENT =	$(SRCS_CLIENT:%.c=%.o)

OBJS_SERVER =   $(SRCS_SERVER:%.c=%.o)

all:		$(NAME_CLIENT)
		$(NAME_SERVER)

client:		$(NAME_CLIENT)

server:		$(NAME_SERVER)

$(NAME_CLIENT):	$(OBJS_CLIENT)
		@$(LIB)
		@echo "-> Compilation client_bin ..."
		$(CC) $(OBJS_CLIENT) -L libmy/ -lmy $(CFLAGS) -o $(NAME_CLIENT) $(LDFLAGS)

$(NAME_SERVER): $(OBJS_SERVER)
		@$(LIB)
		@echo "-> Compilation server_bin ..."
		$(CC) $(OBJS_SERVER) -L libmy/ -lmy $(CFLAGS) -o $(NAME_SERVER) $(LDFLAGS)

clean_client:		
		@echo "-> clean client..."
		@$(RM) $(OBJS_CLIENT)
		@$(LIB_CLEAN)

fclean_client:		clean_client
		@echo "-> fclean client..."
		@$(RM) $(NAME_CLIENT)
		@$(LIB_FCLEAN)

clean_server:
		@echo "-> clean server..."
		@$(RM) $(OBJS_SERVER)
		@$(LIB_CLEAN)

fclean_server: 		clean_server
		@echo "-> fclean server..."
		@$(RM) $(NAME_SERVER)
		@$(LIB_FCLEAN)

re:		fclean all clean

re_client:	fclean_client client clean_client

re_server:	fclean_server server clean_server

.PHONY:		all clean fclean re clean_client clean_server fclean_client fclean_server re_client re_server

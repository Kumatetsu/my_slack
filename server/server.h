#ifndef				__SERVEUR_H__
# define			__SERVEUR_H__

# define			FD_FREE		0
# define			FD_CLIENT	1
# define			FD_SERVER	2
# define			WAITING         3
# define			CONNECTED	4
# define			MAX_FD		255
# define			BUFF_SIZE	3000			

# include			<arpa/inet.h>
# include			<sys/socket.h>
# include			<sys/select.h>
# include			<stdio.h>
# include			<unistd.h>
# include			<stdlib.h>

typedef				void(*vfptr)();

typedef struct			s_user
{
  char				*login;
  int				fd;
  int				type;
  int				state;
  vfptr				fptr_read;
  struct s_user			*next;
}				t_user;

typedef struct			s_node
{
  struct s_node			*next;
  struct s_node			*prev;
  t_user			*user;
}				t_node;

typedef struct			s_chan
{
  char				*name;
  t_node      			*first;
  t_node	        	*last;
  int				pos;
  struct s_chan			*next;
}				t_chan;

typedef struct			s_env
{
  int				port;
  fd_set			fd_write;
  fd_set			fd_read;
  int				fd_max;
  t_user			*list;
  t_chan			*chan;
}				t_env;

typedef				int(*ifptr)(t_env *, char **, int);

typedef struct			s_cmd
{
  char				*cmd;
  ifptr				fptr_cmd;
}				t_cmd;

void		add_client(t_env *e);
t_env		*create_env(int p);
int		check_fd(t_user **list, int fd);
void		add_elem_fd(t_user **list, int fd, int type, vfptr fptr_read);
void		add_elem_chan(t_chan **list, char *name);
void		change_chan(t_chan *list, char *name_chan, int fd);
int		check_user_in_chan(t_node *node, int fd);
void		client_read(t_env *e, int fd);
int		get_cmd(t_env *e, char *buff, int fd);
int		my_exit(t_env *e, char **cmd, int fd);
int		disconnect_chan(t_user *list, t_chan *c, int fd);
int		my_quit(t_env *e, char **cmd, int fd);
int		my_list(t_env *e, char **cmd, int fd);
int		my_nick(t_env *e, char **cmd, int fd);
int		my_users(t_env *e, char **cmd, int fd);
int		my_whisp(t_env *e, char **cmd, int fd);
t_chan		*get_current_chan(t_chan *list, int fd);
t_user		*get_current_user(t_user *list, int fd);
void		show_list(t_user *list, int fd);
void		show_list_chan(t_chan *list, int fd);
void		my_disconnect(t_env *e, int fd);
int		my_join(t_env *e, char **cmd, int fd);
int		my_server(t_env *e);
void		send_msg_in_chan(t_env *e, int fd, char * buf);
void		show_all_user(t_chan *list);
void		move_node_from_chan(t_chan *chan, t_node *n);
t_node		*create_node(t_user *user);
t_node		*get_user_node(t_chan *list, int fd);
void		add_user_to_chan(t_chan *list, t_user *u);
void		move_user_to_chan(t_chan *chan_list, t_chan *chan, char *name_chan, t_user *user);
t_user		*get_current_user_in_chan(t_chan *c, int fd);
void            show_list_users(t_env *e, int fd);
int		my_commands_list(t_env *e, char **cmd, int fd);
void            show_list_commands(t_env *e, int fd);

void		my_putstr(char *);
void		my_putstr_fd(int fd, char *str);
void		my_putnbr_fd(int, int);
void		my_put_nbr(int);
char		*my_strdup(char *);
char		**my_str_to_wordtab(char *, char);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_strlen(char *);
int		tablen(char **);
int		my_getnbr(char *);
#endif

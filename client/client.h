#ifndef		__CLIENT_H_
# define	__CLIENT_H_

#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

# define BUFF_SIZE	1024

typedef		int(*f)();

typedef struct	s_cmd
{
  char		*cmd;
  f		serv_cmd;
}		t_cmd;

void	freetab(char **tab);
int	tablen(char **tab);
void	my_bzero(void *s1, int n);
int	my_connect(char **cmd);
int	get_cmd();
int     my_getnbr(char *str);
void	my_putstr(char *str);
void	my_put_nbr(int i);
char    **my_str_to_wordtab(char *str, char separe);
int	my_strcmp(char *s1, char *s2);
int	my_client(int s);
int	connect_serv(char **cmd);
int	server_cmd();
int	my_server(char **cmd);
int	my_quit(char **cmd);

#endif

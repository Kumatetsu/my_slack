/*
** client_read.c for my_slack in /home/nada/Documents/ETNA/devc/slack/my_slack/server/functions
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Wed Apr 19 19:38:54 2017 MESRATI Nada
** Last update Thu Apr 20 23:13:21 2017 DEBELLEIX Jérémy
*/

#include 		<stdlib.h>
#include 		<stdio.h>
#include		<string.h>
#include 		<unistd.h>
#include 		<netdb.h>
#include		<netinet/in.h>
#include 		<sys/socket.h>
#include 		<arpa/inet.h>
#include		<sys/select.h>
#include		<sys/types.h>
#include        	"../headers/structures.h"
#include        	"../headers/server.h"

int 	get_cmd(t_env *e, char *buf, int fd)
{
  (void)e;
  (void)buf;
  (void)fd;
  my_putstr("get cmd");
  char **tab;
  int  i;

  tab = my_str_to_wordtab(buf, " ");
  i = 0;
  while (g_tab_commands[i].tab[0] != NULL)
    {
      if (my_strcmp(g_tab_commands[i].input, tab[0]) == 0)
        {
	  if (i == 2 || i == 3)
	    {
	      if (tab[1] != NULL)
		g_tab_commands[i].f(e, tab[1], fd);
	      else
	      // TODO Message d'erreur
	    }
	  else
	    g_tab_commands[i].f(e);
          return (1);
        }
      ++i;
    }
  return (0);
}

int my_disconnect(t_env *e, int fd)
{
	(void)e;
	(void)fd;
	my_putstr("disconnect");
	return (0);
}

void		client_read(t_env *e, int fd)
{
  int		r;
  char		buf[BUFF_SIZE];

  r = read(fd, buf, BUFF_SIZE);
  if (r > 0)
    {
      buf[r - 1] = '\0';
      if (!get_cmd(e, buf, fd))
		send_msg_in_chan(e, fd, buf);
    }
  else
    my_disconnect(e, fd);
}

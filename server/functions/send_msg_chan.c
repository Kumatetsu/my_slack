/*
** send_msg_chan.c for my_slack in /home/nada/Documents/ETNA/devc/slack/my_slack/server/functions
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Wed Apr 19 19:47:15 2017 MESRATI Nada
** Last update Wed Apr 19 19:47:18 2017 MESRATI Nada
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

t_channel		*get_current_chan(t_channel *list, int fd)
{
  t_channel	*tmp;
  t_user	*user;

  tmp = list;
  while (tmp)
    {
      user = tmp->first;
      while (user)
	{
	  if (user->cli_addr == fd)
	    return (tmp);
	  user = user->next;
	}
      tmp = tmp->next;
    }
  return (NULL);
}

t_user	*get_current_user(t_user *list, int fd)
{
  t_user	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->cli_addr == fd)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void writing(int fd, char *str, char *buf)
{
    my_putstr_fd(fd, str);
	my_putstr_fd(fd, ": ");
	my_putstr_fd(fd, buf);
	my_putstr_fd(fd, "\n");	
}

void		send_msg_in_chan(t_env *e, int fd, char * buf)
{
  t_user	*user;
  t_channel	*current_chan;
  t_user	*current_user;

  current_chan = get_current_chan(e->first, fd);
  user = (current_chan == NULL) ? NULL : current_chan->first;
  current_user = (!user) ? NULL : get_current_user(user, fd);
  if (!current_chan)
    my_putstr_fd(fd, "send msg: error join a chan before.\n");
  while (user)
    {
      if (FD_ISSET(user->cli_addr, &e->fd_write) && fd != user->cli_addr)
	{
	  if (current_user != NULL && current_user->login)
    	writing(user->cli_addr, current_user->login, buf);
	  else if (current_user != NULL)
    	writing(user->cli_addr, "unknown", buf);
	}
      user = user->next;
    }
}
/*
** send_msg_chan.c for my_slack in /home/nada/Documents/ETNA/devc/slack/my_slack/server/functions
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Wed Apr 19 19:47:15 2017 MESRATI Nada
** Last update Thu Apr 20 22:53:00 2017 BILLAUD Jean
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
  t_node	*node;

  tmp = list;
  while (tmp)
    {
      node = tmp->first;
      while (node)
	{
	  if (node->user->cli_addr == fd)
	    return (tmp);
	  node = node->next;
	}
      tmp = tmp->next;
    }
  return (NULL);
}

t_node	*get_current_user(t_node *list, int fd)
{
  t_node	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->user->cli_addr == fd)
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
  t_node	*n_user;
  t_channel	*current_chan;
  t_node	*current_user;

  current_chan = get_current_chan(e->chan->first, fd);
  n_user = (current_chan == NULL) ? NULL : current_chan->first;
  current_user = (!n_user) ? NULL : get_current_user(n_user, fd);
  if (!current_chan)
    my_putstr_fd(fd, "send msg: error join a chan before.\n");
  while (n_user)
    {
      if (FD_ISSET(n_user->user->cli_addr, &e->fd_write) && fd != n_user->user->cli_addr)
	{
	  if (current_user != NULL && current_user->user->login)
    	writing(n_user->user->cli_addr, current_user->user->login, buf);
	  else if (current_user != NULL)
    	writing(n_user->user->cli_addr, "unknown", buf);
	}
      n_user = n_user->next;
    }
}

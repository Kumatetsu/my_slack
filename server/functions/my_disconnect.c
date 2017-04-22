/*
** my_disconnect.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:07:06 2017 BILLAUD Jean
** Last update Sat Apr 22 19:07:24 2017 BILLAUD Jean
*/

#include 	"../headers/server.h"

void		my_disconnect(t_env *e, int fd)
{
  t_user	*tmp;
  t_chan	*current_chan;
  t_node	*node;

  tmp = e->list;
  close(fd);
  my_putstr("Connection closed\n");
  while (tmp->fd != fd && tmp != NULL)
    tmp = tmp->next;
  if (tmp != NULL && tmp->fd == fd)
    tmp->type = FD_FREE;
  current_chan = get_current_chan(e->chan, fd);
  if (current_chan != NULL)
    {
      node = current_chan->first;
      while (node)
	{
	  if (node->user->fd == fd && node->user->type == FD_CLIENT)
	    {
	      node->user->type = FD_FREE;
	      node->user->login = NULL;
	    }
	  node = node->next;
	}
    }
}

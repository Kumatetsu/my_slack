/*
** change_chan.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server_nada
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 14:39:16 2017 BILLAUD Jean
** Last update Sat Apr 22 18:41:39 2017 BILLAUD Jean
*/

#include 	"../headers/server.h"

void		move_user_to_chan(t_chan *chan_list, t_chan *chan, char *cmd, t_user *user)
{
  t_node	*node;
  
  node = get_user_node(chan_list, user->fd);
  change_chan(chan_list, cmd, user->fd);
  if (!check_user_in_chan(chan->first, user->fd))
    {
      if (chan->first == NULL)
	{
	  chan->first = node;
	  chan->last = node;
	}
      else
	{
	  chan->last->next = node;
	  node->prev = chan->last;
	  chan->last = node;
	}
    }
}

void		change_chan(t_chan *list, char *name_chan, int fd)
{
  t_chan	*tmp;
  t_node	*node;

  tmp = list;
  while (tmp)
    {
      if (my_strcmp(tmp->name, name_chan))
	{
	  node = tmp->first;
	  while (node)
	    {
	      if (node->user->fd == fd && node->user->type == FD_CLIENT)
		move_node_from_chan(tmp, node);
	      node = node->next;
	    }
	}
      tmp = tmp->next;
    }
}

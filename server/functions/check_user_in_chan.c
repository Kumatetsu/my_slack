/*
** check_user_in_chan.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 11:11:11 2017 BILLAUD Jean
** Last update Sat Apr 22 18:42:07 2017 BILLAUD Jean
*/

#include 	"../headers/server.h"

int		check_user_in_chan(t_node *node, int fd)
{
  t_node	*tmp;

  tmp = node;
  while (tmp)
    {
      if (tmp->user->fd == fd && tmp->user->type == FD_CLIENT
	  && tmp->user->state == CONNECTED)
	{
	  my_putstr_fd(fd, "/join : error you already exist in this chan.\n");
	  return (1);
	}
      else if (tmp->user->fd == fd)
	{
	  tmp->user->type = FD_CLIENT;
	  tmp->user->state = CONNECTED;
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

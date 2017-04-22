/*
** my_disconnect.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:07:06 2017 BILLAUD Jean
** Last update Sat Apr 22 22:38:28 2017 BILLAUD Jean
*/

#include 	"../headers/server.h"

void		my_disconnect(t_env *e, int fd)
{
  t_user	*tmp;
  t_user	*current;

  current = get_current_user(e->list, fd);
  tmp = e->list;
  while (tmp)
    {
      if (tmp->next->fd == fd)
	tmp->next = tmp->next->next;
      tmp = tmp->next;
    }
  free_user(current);
  my_putstr("Connection closed\n");
}

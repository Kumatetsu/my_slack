/*
** my_server.c for my_slack in /home/nada/Documents/ETNA/devc/slack/my_slack/server_nada
**
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
**
** Started on  Fri Apr 21 13:35:57 2017 MESRATI Nada
** Last update Tue Apr 25 20:13:07 2017 BILLAUD Jean
*/

#include "../headers/server.h"

int			my_server(t_env *e)
{
  t_user		*tmp;
  t_user		*next;
  
  FD_ZERO(&e->fd_read);
  FD_ZERO(&e->fd_write);
  e->fd_max = 0;
  tmp = e->list;
  add_fd(tmp, e);
  FD_SET(0, &e->fd_read);
  if (select(e->fd_max + 1,
	     &e->fd_read, &e->fd_write, NULL, NULL) == -1)
    return (0);
  tmp = e->list;
  while (tmp != NULL)
    {
      next = tmp->next;
      if (FD_ISSET(tmp->fd, &e->fd_read))
	tmp->fptr_read(e, tmp->fd);
      tmp = next;
    }
  if (FD_ISSET(0, &e->fd_read))
    if(!server_cmd(e, 0))
      return (0);
  return (1);
}


void			add_fd(t_user *tmp, t_env *e)
{
  while (tmp != NULL)
    {
      if (tmp->type != FD_FREE)
	{
	  FD_SET(tmp->fd, &e->fd_read);
	  FD_SET(tmp->fd, &e->fd_write);
	  if (tmp->fd > e->fd_max)
	    e->fd_max = tmp->fd;
	}
      tmp = tmp->next;
    }
}

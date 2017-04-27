/*
** list.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:06:53 2017 BILLAUD Jean
** Last update Tue Apr 25 20:05:34 2017 BILLAUD Jean
*/

#include 	"../headers/server.h"

void		show_list(t_user *list, int fd)
{
  t_user	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr_fd(fd, "fd -> ");
      my_putnbr_fd(fd, tmp->fd);
      my_putstr_fd(fd, "\n");
      tmp = tmp->next;
    }
}

void		show_list_chan(t_chan *list, int fd)
{
  t_chan	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr_fd(fd, tmp->name);
      my_putstr_fd(fd, "\n");
      tmp = tmp->next;
    }
}

void    	show_list_users(t_env *e, int fd)
{
  t_user        *tmp;
  int           unknown;
  
  unknown = -1;
  tmp = e->list;
  while (tmp)
    {
      if (tmp->fd != fd)
        {
          if (tmp->login)
            {
              my_putstr_fd(fd, tmp->login);
              my_putstr_fd(fd, "\n");
            }
          else
            unknown ++;
        }
      tmp = tmp->next;
    }
  if (unknown > 0)
    {
      my_putnbr_fd(fd, unknown);
      my_putstr_fd(fd, " connected user(s) unknown.\n");
    }
}

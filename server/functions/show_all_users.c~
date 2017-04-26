/*
** show_all_users.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:08:16 2017 BILLAUD Jean
** Last update Tue Apr 25 20:32:25 2017 BILLAUD Jean
*/

#include "../headers/server.h"

void		show_all_user(t_chan *list)
{
  t_chan	*tmp;
  t_node	*tmp_user;

  tmp = list;
  while (tmp)
    {
      my_putstr("chan ");
      my_putstr(tmp->name);
      my_putstr(" :\n");
      tmp_user = tmp->first;
      print_on_screen(tmp_user);
      tmp = tmp->next;
    }
}

void		print_on_screen(t_node *u)
{
  while (u)
    {
      if (u->user->type != FD_FREE)
	{
	  if (u->user->login)
	    {
	      my_putstr("-  fd -> ");
	      my_putnbr_fd(1, u->user->fd);
	      my_putstr(" : nickname -> ");
	      my_putstr(u->user->login);
	      my_putstr(" \n\n");
	    }
	  else
	    {
	      my_putstr("-  fd -> ");
	      my_putnbr_fd(1, u->user->fd);
	      my_putstr(" : nickname -> unknown \n\n");
	    }
	}
      u = u->next;
    }
}

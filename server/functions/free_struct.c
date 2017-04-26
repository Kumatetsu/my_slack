/*
** free.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 19:49:52 2017 BILLAUD Jean
** Last update Wed Apr 26 19:38:14 2017 BILLAUD Jean
*/

#include "../headers/server.h"

void	free_user(t_user *u)
{
  if (u->login != NULL)
    {
      free(u->login);
    }
  close(u->fd);
  free(u);
}

void	free_node(t_node *n)
{
  free(n);
}

void	free_chan(t_chan *c)
{
  free(c->name);
  free(c);
}

void	free_env(t_env *e)
{
  free(e);
}

void	free_conv(t_conv *c)
{
  free(c->u_name);
  free(c->conv);
  free(c);
}

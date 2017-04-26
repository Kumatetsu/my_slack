/*
** move_node.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server_nada
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 09:44:32 2017 BILLAUD Jean
** Last update Sat Apr 22 18:25:18 2017 BILLAUD Jean
*/

#include "../headers/server.h"

void	move_node_from_chan(t_chan *c, t_node *n)
{
  if (n == c->first && n == c->last)
    {
      c->first = NULL;
      c->last = NULL;
    }
  else if (n == c->last)
    {
      c->last = n->prev;
      n->prev->next = NULL;
    }
  else if (n == c->first)
    {
      c->first = n->next;
      n->next->prev = NULL;
    }
  else
    {
      n->next->prev = n->prev;
      n->prev->next = n->next;
    }
  n->next = NULL;
  n->prev = NULL;
}

/*
** move_user.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sun Apr 16 11:21:09 2017 BILLAUD Jean
** Last update Thu Apr 20 22:38:57 2017 BILLAUD Jean
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include 	<unistd.h>
#include 	<netdb.h>
#include 	<sys/socket.h>
#include 	<arpa/inet.h>
#include        "../headers/structures.h"
#include        "../headers/server.h"

/*
** Les deux fonctions permettent de:
** - add le user à un autre chan
** - le supprimer de l'ancien chan
*/
void		change_user_channel(t_channel *chan1, t_channel *chan2, t_node *n_user)
{
  remove_user_from_chan(chan1, n_user);
  add_node_to_chan(chan2, n_user);
}

void		remove_user_from_chan(t_channel *channel, t_node *n_user)
{
  if (channel->last == channel->first)
    channel->first = NULL;
  else if (n_user->next == NULL)
    channel->last = n_user->prev;
  else if (n_user->prev == NULL)
    channel->first = n_user->next;
  else
    {
      n_user->next->prev = n_user->prev;
      n_user->prev->next = n_user->next;
    }
  n_user->next = NULL;
  n_user->prev = NULL;
}

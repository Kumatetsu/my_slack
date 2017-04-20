/*
** add_struct.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Thu Apr 13 16:34:07 2017 BILLAUD Jean
** Last update Thu Apr 20 22:38:06 2017 BILLAUD Jean
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
** on insère le user au sein d'un channel, 1ére entrée
*/
void		add_user_to_chan(t_channel *c, t_user *user)
{
  t_node        *node;

  node = create_node(user);
  if (c->first == NULL)
    {
      c->first = node;
      c->last = node;
    }
  else
    {
      c->last->next = node;
      node->prev = c->last;
      c->last = node;
    }
}

void		add_node_to_chan(t_channel *c, t_node *node)
{
  if (c->first == NULL)
    {
      c->first = node;
      c->last = node;
    }
  else
    {
      c->last->next = node;
      node->prev = c->last;
      c->last = node;
    }
}

void	    	add_container_to_env(t_env *env, t_cont_u *c_users, t_cont_c *c_chan)
{
  env->chan = c_chan;
  env->users = c_users;
}

void		add_channel(t_cont_c *c_chan, t_channel *chan)
{
  if (c_chan->first == NULL)
    {
      c_chan->first = chan;
      c_chan->last = chan;
    }
  else
    {
      c_chan->last->next = chan;
      chan->prev = c_chan->last;
      c_chan->last = chan;
    }
}

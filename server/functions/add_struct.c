/*
** add_struct.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Thu Apr 13 16:34:07 2017 BILLAUD Jean
** Last update Tue Apr 18 17:56:23 2017 BILLAUD Jean
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
** on fait les liaison d'une structure chan dans la structure env qui représente le serveur complet
** chan est un channel créé dans lequel les users seront regroupé
*/
void		add_channel_to_env(t_env *env, t_channel *chan)
{
  if (env->first == NULL)
    {
      env->first = chan;
      env->last = chan;
    }
  else
    {
      env->last->next = chan;
      chan->prev = env->last;
      env->last = chan;
    }
}

/*
** on insère le user au sein d'un channel
*/
void		add_user_to_chan(t_channel *chan, t_user *user)
{
  if (chan->first == NULL)
    {
      chan->first = user;
      chan->last = user;
    }
  else
    {
      chan->last->next = user;
      user->prev = chan->last;
      chan->last = user;
    }
}

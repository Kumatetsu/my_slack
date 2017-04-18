/*
** main.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:23:51 2017 BILLAUD Jean
** Last update Tue Apr 18 20:21:51 2017 BILLAUD Jean
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include	<string.h>
#include 	<unistd.h>
#include 	<netdb.h>
#include	<netinet/in.h>
#include 	<sys/socket.h>
#include 	<arpa/inet.h>
#include	<sys/select.h>
#include	<sys/types.h>
#include        "../headers/structures.h"
#include        "../headers/server.h"

int		main()
{
  int		listener;
  t_env		*env;

  listener = init_server();
  env = init_env();
  if (listener != 3)
    return (0);
  my_put_nbr(listener);
  my_putstr(env->first->name);
  my_putstr(env->last->name);
  my_serv(listener, env);
  return (0);
}

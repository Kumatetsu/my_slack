/*
** main.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:23:51 2017 BILLAUD Jean
** Last update Tue Apr 18 16:59:07 2017 BILLAUD Jean
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

int		main(int argc, char **argv)
{
  int		listener;
  t_env		*env;

  if (argc != 2 || my_getnbr(argv[1]) < 1025)
    {
      my_putstr("Usage: ./server_bin [port > 1025]\n\n");
      return (0);
    }
  listener = init_server();
  env = init_env();
  if (listener != 3)
    return (0);
  my_put_nbr(listener);
  my_serv(listener, env);
  return (0);
}

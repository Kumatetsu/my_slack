/*
** my_serv.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Mon Apr 17 11:58:18 2017 BILLAUD Jean
** Last update Thu Apr 20 23:09:01 2017 BILLAUD Jean
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

/*
** Boucle principale du server
*/
void		my_serv(int listener, t_env *env)
{
  int 		fd;
  while(42)
    {
      fd = accept_cli(listener, env);
      client_read(env, fd);
    }
}


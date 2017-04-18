/*
** my_serv.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Mon Apr 17 11:58:18 2017 BILLAUD Jean
** Last update Tue Apr 18 17:27:52 2017 BILLAUD Jean
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

void		my_serv(int listener, t_env *env)
{
  while(42)
    {
      accept_cli(listener, env);
    }
}

void			accept_cli(int listener, t_env *env)
{
  struct sockaddr_in	cli_addr;
  int			client;
  socklen_t		socklen;
  t_user		*user;

  
  socklen = sizeof(cli_addr);
  client = accept(listener, (struct sockaddr *)&cli_addr, &socklen);
  user = create_user("toto", client);
  add_user_to_chan(env->first, user);
  send(client, "Welcome to my_slack\n", strlen("Welcome to my_slack\n"), MSG_DONTWAIT);
  notify_new_user(env->first);
}

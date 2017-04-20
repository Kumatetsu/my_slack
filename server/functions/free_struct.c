/*
** free_struct.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sun Apr 16 11:11:46 2017 BILLAUD Jean
*/

#include 		<stdlib.h>
#include 		<stdio.h>
#include		<string.h>
#include 		<unistd.h>
#include 		<netdb.h>
#include		<netinet/in.h>
#include 		<sys/socket.h>
#include 		<arpa/inet.h>
#include		<sys/select.h>
#include		<sys/types.h>
#include        	"../headers/structures.h"
#include        	"../headers/server.h"

void	free_user(t_user *user)
{
  free(user->login);
  free(user);
}

void	free_channel(t_channel *channel)
{
  free(channel->name);
  free(channel);
}

void	free_env(t_env	*env)
{
  free(env);
}

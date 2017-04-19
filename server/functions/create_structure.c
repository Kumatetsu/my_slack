/*
** create_structure.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:24:35 2017 BILLAUD Jean
** Last update Tue Apr 18 17:59:54 2017 BILLAUD Jean
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
** On créé la structure envorinnement qui est un simple container permettant 
** de contenir tous les channels
*/
t_env		*create_env()
{
  t_env		*env;

  env = NULL;
  env = malloc(sizeof (*env));
  if (env == NULL)
    {
      my_putstr("ERROR: CREATE ENV ABORT");
      return (0);
    }
  env->first = NULL;
  env->last  = NULL;
  my_putstr("INFO: L'environnement a bien été créé\n");
  return (env);
}

/*
** Le user contient deux informations: son login permettant
** de le retrouver avec un get_user_by_name()
** et le cli_addr est le file descriptor qui permet au serv
** de communiquer avec la bonne socket;
*/
t_user		*create_user(char *login, int cli_addr)
{
  t_user	*user;

  user = NULL;
  user = malloc(sizeof (*user));
  if (user == NULL)
    {
      my_putstr("ERROR: Le user n'a pu être créé\n");
      return (0);
    }
  user->login = my_strdup(login);
  user->cli_addr = cli_addr;
  user->next = NULL;
  user->prev = NULL;
  my_putstr("INFO: Le user a bien été créé\n");
  return (user);
}

/*
** creation du channel qui contient les structs des
** users présents sur le serv.
*/
t_channel	*create_channel(char *cli_name)
{
  t_channel	*channel;

  channel = NULL;
  channel = malloc(sizeof (*channel));
  if (channel == NULL)
    {
      my_putstr("ERROR: Le channel n'a pu être créé\n");
      return (0);
    }
  channel->name = my_strdup(cli_name);
  channel->first = NULL;
  channel->last = NULL;
  channel->next = NULL;
  channel->prev = NULL;
  my_putstr("INFO: Le channel a bien été créé\n");
  return (channel);
}

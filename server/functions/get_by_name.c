/*
** get_by_name.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 19 21:10:57 2017 BILLAUD Jean
** Last update Wed Apr 19 21:24:07 2017 BILLAUD Jean
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include 	<unistd.h>
#include 	<netdb.h>
#include 	<sys/socket.h>
#include 	<arpa/inet.h>
#include        "../headers/structures.h"
#include        "../headers/server.h"

t_channel	*get_chan_by_name(t_env *env, char *name)
{
  t_channel	*tmp;

  tmp = env->first;
  while (tmp != NULL)
    {
      if (my_strcmp(name, tmp->name) == 0)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

t_user		*get_user_by_name(t_env	*env, char *name)
{
  t_channel	*tmp;
  t_user	*intmp;

  tmp = env->first;
  while (tmp != NULL)
    {
      intmp = tmp->first;
      while (intmp != NULL)
	{
	  if (my_strcmp(name, intmp->login) == 0)
	    return (intmp);
	  intmp = intmp->next;
	}
      tmp = tmp->next;
    }
  return (NULL);
}

/*
** set_fd.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Thu Apr 20 23:20:10 2017 BILLAUD Jean
** Last update Thu Apr 20 23:23:09 2017 BILLAUD Jean
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

void			set_fd(t_env *env)
{
  t_user		*tmp;

  tmp = env->users->first;
  for (tmp = env->users->first; tmp != NULL; tmp = tmp->next)
    {
      FD_SET(tmp->cli_addr, &env->fd_read);
    }
}

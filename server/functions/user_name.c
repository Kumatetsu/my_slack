/*
** user_name.c for my_slack in /home/naej/ETNA/my_slack
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Tue Apr 18 21:25:16 2017 BILLAUD Jean
** Last update Wed Apr 19 20:50:53 2017 BILLAUD Jean
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

void			ask_user_name(t_env *env)
{
  fd_set		readfs;
  int			nread;
  char			buffer[140];
  t_user		*tmp;
  int			i;
  struct timeval	tv;

  i = 4;
  tv.tv_sec = 5;
  tv.tv_usec = 0;
  if (env->last->first != NULL)
    {
      tmp = env->last->first;
      FD_ZERO(&readfs);
      while (tmp != NULL)
	{
	  FD_SET(tmp->cli_addr, &readfs);
	  i += 1;
	  tmp = tmp->next;
	}
      FD_SET(0, &readfs);
      tmp = env->last->first;
      select(i, &readfs, NULL, NULL, &tv);
      while (tmp != NULL)
	{
	  if (FD_ISSET(tmp->cli_addr, &readfs))
	    {
	      my_putstr("client name....\n");
	      memset(buffer, 0, 140);
	      nread = read(tmp->cli_addr, buffer, 140);
	      buffer[nread] = '\0';
	      free(tmp->login);
	      tmp->login = my_strdup(buffer);
	      change_user_channel(env->last, env->first, tmp);
	      FD_CLR(tmp->cli_addr, &readfs);
	    }
	  tmp = tmp->next;
	}
    }
}

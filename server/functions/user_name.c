/*
** user_name.c for my_slack in /home/naej/ETNA/my_slack
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Tue Apr 18 21:25:16 2017 BILLAUD Jean
** Last update Tue Apr 18 22:12:02 2017 BILLAUD Jean
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

void		ask_user_name(t_channel *chan)
{
  fd_set	readfs;
  int		nread;
  char		buffer[20];
  t_user	*tmp;
  int		i;

  i = 4;
  tmp = chan->first;
  FD_ZERO(&readfs);
  while (tmp != NULL)
    {
      FD_SET(tmp->cli_addr, &readfs);
      i += 1;
      tmp = tmp->next;
    }
  FD_SET(0, &readfs);
  tmp = chan->first;
  select(i, &readfs, NULL, NULL, NULL);  
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->cli_addr, &readfs))
	{
	  my_putstr("client name....\n");
	  memset(buffer, 0, 20);
	  nread = read(tmp->cli_addr, buffer, 20);
	  buffer[nread] = '\0';
	  my_putstr(buffer);
	  FD_CLR(tmp->cli_addr, &readfs);
	}
      tmp = tmp->next;
    }
}

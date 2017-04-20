/*
** create_construct.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server/headers
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Thu Apr 20 21:11:58 2017 BILLAUD Jean
** Last update Thu Apr 20 23:23:38 2017 BILLAUD Jean
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

t_cont_u	*create_cont_u()
{
  t_cont_u      *cont_u;
  
  cont_u = NULL;
  cont_u = malloc(sizeof (*cont_u));
  if (cont_u == NULL)
    {
      my_putstr("ERROR: CREATE CONS ABORT");
      return (0);
    } 
  cont_u->first = NULL;
  cont_u->last = NULL;
  my_putstr("INFO: Cons_u créé\n");
  return (cont_u);
}

t_cont_c	*create_cont_c()
{
  t_cont_c      *cont_c;
  
  cont_c = NULL;
  cont_c = malloc(sizeof (*cont_c));
  if (cont_c == NULL)
    {
      my_putstr("ERROR: CREATE CONS ABORT");
      return (0);
    } 
  cont_c->first = NULL;
  cont_c->last = NULL;
  my_putstr("INFO: Cons_u créé\n");
  return (cont_c);
}

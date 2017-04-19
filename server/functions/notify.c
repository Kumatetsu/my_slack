/*
** notify.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Tue Apr 18 17:11:52 2017 BILLAUD Jean
** Last update Tue Apr 18 18:05:43 2017 BILLAUD Jean
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

/*
** Previent tous les utilisateurs du channel actuel qu'un nouveau
** est arrivé
**
*/
void			notify_new_user(t_channel *chan)
{
  t_user		*tmp;

  tmp = chan->first;
  while (tmp->next)
    {
      send(tmp->cli_addr, "Un nouvel utilisateur vient de se connecter\n",strlen("Un nouvel utilisateur vient de se connecter\n"), MSG_DONTWAIT);
      tmp = tmp->next;
    }
}

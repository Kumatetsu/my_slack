/*
** init_serv.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sun Apr 16 13:21:13 2017 BILLAUD Jean
** Last update Tue Apr 18 20:20:00 2017 BILLAUD Jean
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
** On définit le port sur lequel on doit se connecter
** Le backlog représente la taille maximum de client en
** attente dans la file de connexion
*/
#define PORT 4242
#define BACKLOG 512

/*
** On crée la socket pour le server
** On retourne son file descriptor
*/
int			init_server()
{
  int			listener;
  struct sockaddr_in	srv_addr;
  struct protoent	*proto;

  if ((proto = getprotobyname("TCP")) == NULL)
    return (EXIT_FAILURE);
  if ((listener = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    {
      perror(__FUNCTION__);
      return (EXIT_FAILURE);
    }
  srv_addr.sin_family = AF_INET;
  srv_addr.sin_addr.s_addr = INADDR_ANY;
  srv_addr.sin_port = htons(PORT);
  if ((bind(listener, (const struct sockaddr*)&srv_addr, sizeof(srv_addr))) == -1)
    {
      perror(__FUNCTION__);
      return (EXIT_FAILURE);
    }
  if ((listen(listener, BACKLOG)) == -1)
    {
      perror(__FUNCTION__);
      return (EXIT_FAILURE);
    }
  return (listener);
}

/*
** On initialise la struc env et le chan
** général
*/
t_env			*init_env()
{
  t_env			*env;
  t_channel		*chan;
  t_channel		*waitin;

  env = create_env();
  chan = create_channel("general");
  waitin = create_channel("101010");
  add_channel_to_env(env, chan);
  add_channel_to_env(env, waitin);
  return (env);
}

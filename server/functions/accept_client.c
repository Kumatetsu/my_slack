/*
** accept_client.c for my_slack in /home/naej/ETNA/my_slack/server/functions
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Mon Apr 17 11:56:40 2017 BILLAUD Jean
** Last update Thu Apr 20 23:12:36 2017 BILLAUD Jean
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
** crée le file descriptor du cli et le place dans void
**
*/
int			accept_cli(int listener, t_env *env)
{
  struct sockaddr_in	cli_addr;
  int			client;
  socklen_t		socklen;
  t_user		*user;

  
  socklen = sizeof(cli_addr);
  if((client = accept(listener, (struct sockaddr *)&cli_addr, &socklen)) == -1)
    return (EXIT_FAILURE);
  user = create_user(client);
  add_user_to_chan(env->chan->first, user);
  send(client, "Welcome to my_slack\n", strlen("Welcome to my_slack\n"), MSG_DONTWAIT);
  return user->cli_addr;
}

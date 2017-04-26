/*
** connect.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 17:19:19 2017 MESRATI Nada
** Last update Tue Apr 25 19:51:55 2017 BILLAUD Jean
*/

#include		<string.h>
#include		"client.h"

/**
 ** Prend la commande tapé par le client et se connecte au serveur avec le prototype TCP
 ** en créant une socket.
 ** Renvoie la socket une fois connecté
 ** pour la fonction connect on est obligé de cast sockaddr_in en sockadd
 **/
int			my_connect(char **cmd)
{
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			s;
  int			port;

  memset(&sin, 0, sizeof (struct sockaddr_in));
  if (cmd[1] != NULL)
    port = my_getnbr(cmd[1]);
  pe = getprotobyname("TCP");
  if (pe == NULL)
    return (-1);
  s = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (s == -1)
    return (-1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(cmd[0]);
  if (connect(s, (const struct sockaddr *)&sin, sizeof (sin)) == -1)
    {
      my_putstr("Error connect()\n");
      return (-1);
    }
  freetab(cmd);
  return (s);
}

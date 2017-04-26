/*
** main.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 17:18:58 2017 MESRATI Nada
** Last update Tue Apr 25 19:54:29 2017 BILLAUD Jean
*/

#include	"client.h"

int		main()
{
  int		s;

  while((s = server_cmd()) < 0);
  if (s > 0)
    my_client(s);
  return (0);
}

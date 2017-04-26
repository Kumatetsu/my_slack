/*
** main.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 17:18:58 2017 MESRATI Nada
** Last update Wed Apr 26 20:37:11 2017 BILLAUD Jean
*/

#include	"client.h"

int		main()
{
  int		s;

  my_putstr_color("clear", "");
  my_putstr("Bienvenu sur votre client my_slack\n");
  my_putstr("cmd: /server [ip]:[port]\n");
  my_putstr("/quit\n");
  while((s = server_cmd()) < 0);
  if (s > 0)
    my_client(s);
  return (0);
}

/*
** get_cmd.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 17:19:35 2017 MESRATI Nada
** Last update Wed Apr 26 20:39:23 2017 BILLAUD Jean
*/
#include "client.h"

t_cmd	g_tab[] =
  {
    {"/server", &my_server},
    {"/quit", &my_quit},
    {NULL, NULL}
  };

int	server_cmd()
{
  int	r;
  int   i;
  char	buf[BUFF_SIZE];

  i = 0;
  my_putstr_color("red", "~>");
  r = read(0, buf, BUFF_SIZE - 1);
  if (r > 0)
    {
      buf[r - 1] = '\0';
      i = get_cmd(buf);
    }
  return (i);
}
  
/** 
 ** Cette fonction sert à se connecter au serveur avec la commande /server [address]:[port]
 ** Elle fait la vérification de la commande et si le format est bon fait appel à my_connect()
 ** Il faut voir le my_str_to_wordtab dans la lib, il prend en deuxième argument le caractère de séparation
 **/

int	get_cmd(char *buff)
{
  char	**cmd;
  int	i;
  int	r;

  i = -1;
  r = 0;
  cmd = NULL;
  if (buff[0] != '\0')
    {
      cmd = my_str_to_wordtab(buff, ' ');
      if (cmd[0] == NULL)
	{
	  freetab(cmd);
	  return (-1);
	}
      while (g_tab[++i].cmd != NULL && my_strcmp(cmd[0], g_tab[i].cmd));
      if (g_tab[i].cmd == NULL)
	{
	  freetab(cmd);
	  return (-1);
	}
      r = g_tab[i].serv_cmd(cmd);
      freetab(cmd);
    }
    return (r);
}


int	my_server(char **cmd)
{
  char	**tmp;
  int	i;

  i = 0;
  if (tablen(cmd) == 2 && my_strcmp(cmd[0], "/server") == 0)
    {
      tmp = my_str_to_wordtab(cmd[1], ':');
      if(tablen(tmp) != 2 || my_getnbr(tmp[0]) == -1
	 || my_getnbr(tmp[1]) == -1)
	{
	  freetab(tmp);
	  my_putstr("Usage: /server [address]:[port]\n");
	  return (-1);
	}
      if ((i = my_connect(tmp)) != -1)
	return (i);
    }
  else
    my_putstr("Usage: /server [address]:[port]\n");
  return (-1);
}

int	my_quit(char **cmd)
{
  if (tablen(cmd) < 2)
    {
      my_putstr("salut, à la prochaine\n");
      return (0);
    }
  my_putstr("Usage: /quit\n");
  return (-1);
}

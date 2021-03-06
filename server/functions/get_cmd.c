/*
** get_cmd.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:06:36 2017 BILLAUD Jean
** Last update Thu Apr 27 16:55:39 2017 BILLAUD Jean
*/

#include 	"../headers/server.h"

t_cmd		g_tab[] =
  {
    {"/nick", &my_nick},
    {"/list", &my_list},
    {"/join", &my_join},
    {"/quit", &my_quit},
    {"/exit", &my_exit},
    {"/users", &my_users},
    {"/whisp", &my_whisp},
    {"/help", &my_commands_list},
    {NULL, NULL}
  };

int		get_cmd(t_env *e, char *buff, int fd)
{
  char		**cmd;
  int		i;

  i = -1;
  if (buff[0] != '\0')
    {
      cmd = my_str_to_wordtab(buff, ' ');
      if (cmd[0] == NULL)
	{
	  freetab(cmd);
	  return (0);
	}
      while (g_tab[++i].cmd != NULL 
	     && my_strcmp(cmd[0], g_tab[i].cmd));
      if (g_tab[i].cmd == NULL)
	{
	  freetab(cmd);
	  return (0);
	}
      g_tab[i].fptr_cmd(e, cmd, fd);
      show_all_user(e->chan);
      freetab(cmd);
      return (1);
    }
  return (0);
}

int   my_commands_list(t_env *e, char **cmd, int fd)
{
  if (tablen(cmd) == 1)
    show_list_commands(e, fd);
  else
    my_putstr_fd(fd, "/help : error, too much arguments.\n");
  return (0);
}

void            show_list_commands(t_env *e, int fd)
{
  t_chan        *chan;
  int           i;

  i = 0;
  if ((chan = get_current_chan(e->chan, fd)))
    {
      if (chan->name)
	{
	  my_putstr_fd(fd, "Current channel : ");
	  my_putstr_fd(fd, chan->name);
	}
    }
  else
    my_putstr_fd(fd, "You are in any channel");
  my_putstr_fd(fd, "\nCommandes possibles :\n");
  while (g_tab[i].cmd != NULL)
    {
      my_putstr_fd(fd, g_tab[i].cmd);
      my_putstr_fd(fd, "\n");
      ++i;
    }
}

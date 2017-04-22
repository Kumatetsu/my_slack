/*
** get_cmd.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:06:36 2017 BILLAUD Jean
** Last update Sat Apr 22 22:12:37 2017 BILLAUD Jean
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
	return (0);
      while (g_tab[++i].cmd != NULL 
	     && my_strcmp(cmd[0], g_tab[i].cmd));
      if (g_tab[i].cmd == NULL)
	return (0);
      else
	g_tab[i].fptr_cmd(e, cmd, fd);
      show_all_user(e->chan);
      return (1);
    }
  return (0);
}

int		my_exit(t_env *e, char **cmd, int fd)
{
  t_chan        *tmp;

  tmp = e->chan;
  if (tablen(cmd) == 1)
    {
      while (tmp)
	{
	  disconnect_chan(tmp->first, tmp, fd);
	  tmp = tmp->next;
	}
    }
  my_putstr_fd(fd, "disconnected.\n");
  my_disconnect(e, fd);
  return (0);
  my_putstr_fd(fd, "disconnected.\n");
  return (0);
}

int		disconnect_chan(t_node *n, t_chan *c, int fd)
{
  t_node	*tmp;

  tmp = n;
  while (n)
    {
      if (tmp->user->fd == fd && tmp->user->type == FD_CLIENT)
	{
	  tmp->user->state = WAITING;
	  move_node_from_chan(c, tmp);
	  free_node(tmp);
	  my_putstr_fd(fd, "You leave the chan ");
	  my_putstr_fd(fd, c->name);
	  my_putstr_fd(fd, " \n");
	  return (0);
	}
      n = n->next;
    }
  return (0);
}

int		my_quit(t_env *e, char **cmd, int fd)
{
  t_chan	*tmp;

  tmp = e->chan;
  if (tablen(cmd) != 1)
    {
      my_putstr_fd(fd, "/quit : error too much arguments.\n");
      return (0);
    }
  while (tmp)
    {
      disconnect_chan(tmp->first, tmp, fd);
      tmp = tmp->next;
    }
  return (0);
}

int		my_list(t_env *e, char **cmd, int fd)
{
  t_chan	*tmp;

  if (tablen(cmd) == 1)
    show_list_chan(e->chan, fd);
  else if (tablen(cmd) == 2)
    {
      tmp = e->chan;
      while (tmp)
	{
	  if (!my_strncmp(tmp->name, cmd[1], my_strlen(cmd[1])))
	    my_putstr_fd(fd, tmp->name);
	  tmp = tmp->next;
	}
    }
  else
    my_putstr_fd(fd, "/list : error, too much arguments.\n");
  return (0);
}

int		my_nick(t_env *e, char **cmd, int fd)
{
  /*A FAIRE*/
  (void)e;
  (void)cmd;
  (void)fd;
  return (0);
}

int		my_users(t_env *e, char **cmd, int fd)
{
  /*A FAIRE*/
  (void)e;
  (void)cmd;
  (void)fd;
  return (0);
}

int		my_whisp(t_env *e, char **cmd, int fd)
{
  /*A FAIRE*/
  (void)e;
  (void)cmd;
  (void)fd;
  return (0);
}

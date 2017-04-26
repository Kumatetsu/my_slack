/*
** cmd_list.c for  in /Volumes/SD/ETNA/slack/my_slack/server/functions
** 
** Made by DEBELLEIX Jérémy
** Login   <debell_j@etna-alternance.net>
** 
** Started on  Mon Apr 24 18:39:37 2017 DEBELLEIX Jérémy
** Last update Wed Apr 26 17:18:01 2017 BILLAUD Jean
*/

#include        "../headers/server.h"

int             my_list(t_env *e, char **cmd, int fd)
{
  t_chan        *tmp;

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

int   		my_users(t_env *e, char **cmd, int fd)
{
  if (tablen(cmd) == 1)
    show_list_users(e, fd);
  else
    my_putstr_fd(fd, "/users : error, too much arguments.\n");
  return (0);
}

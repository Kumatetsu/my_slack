/*
** my_nick.c for  in /Volumes/SD/ETNA/slack/my_slack/server/functions
** 
** Made by DEBELLEIX Jérémy
** Login   <debell_j@etna-alternance.net>
** 
** Started on  Mon Apr 24 18:48:28 2017 DEBELLEIX Jérémy
** Last update Tue Apr 25 20:07:31 2017 BILLAUD Jean
*/

#include        "../headers/server.h"

int   		my_nick(t_env *e, char **cmd, int fd)
{
  t_user	*user;

  user = get_current_user(e->list, fd);
  if (cmd[2])
      my_putstr_fd(fd, "/nick : error, too much arguments.\n");
  else if (cmd[1])
    {
      if (user->login && my_strcmp(cmd[1], user->login) == 0)
	my_putstr_fd(fd, "It's your actual nickname");
      else if (is_existing_login(e, fd, cmd[1]))
	my_putstr_fd(fd, "Nickname still exists\n");
      else
	user->login = my_strdup(cmd[1]);
    }
  else
    my_putstr_fd(fd, "/nick : error, argument missed.\n");
  return (0);
}

int    		is_existing_login(t_env *e, int fd, char *login)
{
  t_user        *tmp;

  tmp = e->list;
  while (tmp)
    {
      if (tmp->fd != fd && tmp->login)
        {
          if (my_strcmp(tmp->login, login) == 0)
            return (1);
        }
      tmp = tmp->next;
    }
  return (0);
}

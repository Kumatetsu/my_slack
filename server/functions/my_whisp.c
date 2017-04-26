/*
** my_whisp.c for  in /Volumes/SD/ETNA/slack/my_slack/server/functions
** 
** Made by DEBELLEIX Jérémy
** Login   <debell_e@etna-alternance.net>
** 
** Started on  Mon Apr 24 18:43:47 2017 DEBELLEIX Jérémy
** Last update Tue Apr 25 20:17:24 2017 BILLAUD Jean
*/

#include        "../headers/server.h"

int   		my_whisp(t_env *e, char **cmd, int fd)
{
  int		isExistingUser;

  if (tablen(cmd) < 3)
    my_putstr_fd(fd, "/users : error, too few arguments.\n");
  else
    {
      isExistingUser = is_existing_user(cmd[1], e, fd);
      if (isExistingUser == 1)
          send_direct_msg(e, cmd, fd);
      else
        my_putstr_fd(fd, "This user doesn't exist");
    }
  return (0);
}

void            send_direct_msg(t_env *e, char **cmd, int fd)
{
  t_user        *tmp;
  int           i;

  i = 1;
  tmp = e->list;
  while (tmp)
    {
      if (tmp->login)
        {
          if (my_strcmp(tmp->login, cmd[1]) == 0)
            {
              show_sender(e, fd, tmp->fd);
              while (cmd[++i])
                {
                  my_putstr_fd(tmp->fd, cmd[i]);
                  my_putstr_fd(tmp->fd, " ");
                }
              my_putstr_fd(tmp->fd, "\n");
            }
        }
      tmp = tmp->next;
    }
}

void       	show_sender(t_env *e, int fd_sender, int fd_receiver)
{
  t_user        *sender;

  sender = get_current_user(e->list, fd_sender);
  my_putstr_fd(fd_receiver, "Message from ");
  if (sender->login)
    my_putstr_fd(fd_receiver, sender->login);
  else
    my_putstr_fd(fd_receiver, "unknown user");
  my_putstr_fd(fd_receiver, " : ");
}

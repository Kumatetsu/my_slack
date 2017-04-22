/*
** send_msg_in_chan.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:08:06 2017 BILLAUD Jean
** Last update Sat Apr 22 19:21:26 2017 BILLAUD Jean
*/

#include 	"../headers/server.h"

void		writing(int fd, char *login, char *buf)
{
  my_putstr_fd(fd, login);
  my_putstr_fd(fd, ": ");
  my_putstr_fd(fd, buf);
  my_putstr_fd(fd, "\n");
}

void		send_msg_in_chan(t_env *e, int fd, char * buf)
{
  t_node	*node;
  t_chan	*current_chan;
  t_user	*current_user;

  current_chan = get_current_chan(e->chan, fd);
  node = (current_chan == NULL) ? NULL : current_chan->first;
  current_user = (!node) ? NULL : get_current_user_in_chan(current_chan, fd);
  if (!current_chan)
    my_putstr_fd(fd, "send msg: error join a chan before.\n");
  while (node)
    {
      if (FD_ISSET(node->user->fd, &e->fd_write) && fd != node->user->fd &&
	  node->user->type == FD_CLIENT)
	{
	  if (current_user != NULL && current_user->login)
	    writing(node->user->fd, current_user->login, buf);
	  else if (current_user != NULL)
	    writing(node->user->fd, "unknown", buf);
	}
      node = node->next;
    }
}

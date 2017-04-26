/*
** client_read.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:06:18 2017 BILLAUD Jean
** Last update Tue Apr 25 18:36:59 2017 BILLAUD Jean
*/

#include "../headers/server.h"

void	client_read(t_env *e, int fd)
{
  int	r;
  char	buf[BUFF_SIZE];

  r = read(fd, buf, BUFF_SIZE - 1);
  if (r > 0)
    {
      buf[r - 1] = '\0';
      if (!get_cmd(e, buf, fd))
	send_msg_in_chan(e, fd, buf);
    }
  else
    my_disconnect(e, fd);
}

int	server_cmd(t_env *e, int fd)
{
  int	r;
  char	buf[BUFF_SIZE];

  r = read(fd, buf, BUFF_SIZE - 1);
  if (r > 0)
    {
      buf[r - 1] = '\0';
      if(!get_serv_cmd(e, buf))
	return (0);
    }
  return (1);
}

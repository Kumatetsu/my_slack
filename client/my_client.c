/*
** my_client.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Apr 18 16:30:20 2017 MESRATI Nada
** Last update Tue Apr 25 19:55:13 2017 BILLAUD Jean
*/

#include "client.h"
 
int		send_input(int s)
{
  char		buff[BUFF_SIZE];
  int		r;
  
  my_bzero(buff, BUFF_SIZE);
  r = read(0, buff, BUFF_SIZE);
  if (r > 0)
    {
      buff[r] = '\0';
      write(s, buff, r);
      return (1);
    }
  else
    {
      write(1, "exit\n", 5);
      return (0);
    }
}

int		get_msg(int s)
{
  char		buff[BUFF_SIZE];
  int		r;
  
  my_bzero(buff, BUFF_SIZE);
  r = recv(s, buff, BUFF_SIZE, 0);
  if (r > 0)
    {
      buff[r] = '\0';
      write(1, buff, r);
      return (1);
    }
  else
    {
      write(1, "Connection closed\n", 18);
      return (0);
    }
}

/*
** Cette fonction fait la boucle du client et selon si c'est une reception du message ou son envoi
** fait appel respectivement aux fonction get_msg et send_input
*/

int		my_client(int s)
{
  fd_set	fd_read;
  int		r;
  
  r = 1;
  while (r)
    {
      FD_ZERO(&fd_read);
      FD_SET(0, &fd_read);
      FD_SET(s, &fd_read);
      if (select(s + 1, &fd_read, NULL, NULL, NULL) == 1)
	r = 0;
      if (FD_ISSET(0, &fd_read))
	r = send_input(s);
      if (FD_ISSET(s, &fd_read))
	r = get_msg(s);
    }
  return (0);
}

/*
** my_putstr_fd.c for my_slack in /home/nada/Documents/ETNA/devc/slack/my_slack/server/functions
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Wed Apr 19 20:51:05 2017 MESRATI Nada
** Last update Fri Apr 21 14:26:58 2017 MESRATI Nada
*/

#include "server.h"

void	my_putstr_fd(int fd, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(fd, &str[i], 1);
      i++;
    }
}
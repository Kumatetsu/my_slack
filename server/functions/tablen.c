/*
** tablen.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 18:08:23 2017 BILLAUD Jean
** Last update Sat Apr 22 18:26:28 2017 BILLAUD Jean
*/

#include "../headers/server.h"

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

/*
** my_getnbr.c for my_getnbr in /home/mesrat_n/piscine/C/Jour03/mesrat_n/my_getnbr
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Thu Oct  2 11:07:05 2014 MESRATI Nada
** Last update Tue Mar 28 17:32:39 2017 MESRATI Nada
*/
#include <stdlib.h>
#include <stdio.h>

int     my_getnbr(char *str)
{
  int   i;
  int   nb;
  int   neg;
 
  if (!str)
    return (0);
  neg = 1;
  for (i = 0; !(str[i] >= '0' && str[i] <= '9'); i++);
  if (str[i - 1] == '-')
    neg = -1;
  for (nb = 0; str[i] >= '0' && str[i] <= '9'; i++)
    {
      nb *= 10;
      nb += str[i] - '0';
    }
  return (nb * neg);
}

/*
** my_putnbr_base.c for my_putnbr_base in /home/mesrat_n/piscine/C/Jour05/mesrat_n/my_putnbr_base
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Fri Oct  3 12:12:33 2014 MESRATI Nada
** Last update Thu Oct  9 12:24:37 2014 MESRATI Nada
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	my_putchar(char c);

void	my_putstr(char *str);

int     my_strlen(char  *str);

int	my_putnbr_base(int nbr, char *base)
{
  char	array[256];
  int   len;
  int	i;
  int	tmp;
  int	j;
  
  if (nbr < 0)
    {
      nbr = -nbr;
      my_putchar('-');
    }
  for (i = 0, tmp = nbr, len = my_strlen(base); nbr > 0; i++)
      nbr /= len;
  for (j= 0; i > 0; i--, j++, tmp /= len)
    {
      array[j] = (base[tmp % len]);
    }
  array[j] = '\0';
  for (j-- ; j >= 0; j--)
      my_putchar(array[j]);
return (0);
}

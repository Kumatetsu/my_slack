
/*
** my_aff_tab.c for my_aff_tab in /home/mesrat_n/piscine/C/Jour02
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Sep 30 10:47:18 2014 MESRATI Nada
** Last update Thu Oct  9 20:07:22 2014 MESRATI Nada
*/

#include <stdlib.h>
#include <stdio.h>

void	my_putchar(char c);

void    my_put_nbr(int n);

void	my_aff_tab(int tab[], int len)
{
  int	i;

  for (i = 0; i < len; i++)
    {
      my_put_nbr(tab[i]);
      my_putchar('\n');
    }
}

/*
** my_put_nbr.c for my_put_nbr in /home/mesrat_n/piscine/C/Jour01/mesrat_n/my_put_nbr
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Mon Sep 29 15:58:52 2014 MESRATI Nada
** Last update Thu Oct  9 10:11:58 2014 MESRATI Nada
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	my_putchar(char c);

void	my_put_nbr(int n)
{
  int	quotient;
  int	n2;

  quotient = 1;
  if (n == -2147483648)
    {
      write(1, "-2147483648", 11);
      return;
    }
  if (n < 0 && n != -2147483648)
    {
      n *= -1;
      my_putchar('-');
    }
  n2 = n;
  while (n >= 10)
    {
      n = n / 10;
      quotient *= 10;
    }
  while (quotient > 0)
    {
      my_putchar(48 + (n2 / quotient % 10));
      quotient = quotient / 10;
    }
}

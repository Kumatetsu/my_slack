/*
** my_putstr.c for my_putstr in /home/mesrat_n/piscine/C
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Sat Oct  4 16:11:36 2014 MESRATI Nada
** Last update Tue Mar 28 17:32:55 2017 MESRATI Nada
*/
#include <unistd.h>

void	my_putchar(char c);

void	my_putstr(char *str)
{
  int	i;

  for (i = 0; str[i] != '\0'; i++)
    {
      my_putchar(str[i]);
    }
}

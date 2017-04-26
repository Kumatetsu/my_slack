/*
** my_putchar.c for my_putchar in /home/mesrat_n/piscine/C
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Sat Oct  4 16:08:31 2014 MESRATI Nada
** Last update Sat Oct  4 21:21:20 2014 MESRATI Nada
*/
#include <unistd.h>

void	my_putchar(char	c)
{
  write(1, &c, 1);
}

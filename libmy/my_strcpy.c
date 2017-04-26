/*
** my_strcpy.c for my_strcpy in /home/mesrat_n/piscine/C/Jour04/mesrat_n/my_strcpy
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Thu Oct  2 10:26:29 2014 MESRATI Nada
** Last update Sat Oct  4 21:25:14 2014 MESRATI Nada
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && src != NULL && dest != NULL)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

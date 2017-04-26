/*
** my_strncpy.c for my_strncpy in /home/mesrat_n/piscine/C/Jour04/mesrat_n/my_strncpy
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Thu Oct  2 12:50:39 2014 MESRATI Nada
** Last update Sat Oct  4 21:25:42 2014 MESRATI Nada
*/

#include <stdlib.h>

int     my_strlen(char  *str);

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n && src != NULL && dest != NULL)
    {
      dest[i] = src[i];
      i++;
    }
  if (my_strlen(src) < n)
    {
      while (dest[i] != '\0')
	{
	  dest[i] = '\0';
	  i++;
	}
    }
  return (dest);
}

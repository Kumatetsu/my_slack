/*
** my_strstr.c for strstr in /home/mesrat_n/piscine/C/libmy
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Sat Oct  4 19:30:55 2014 MESRATI Nada
** Last update Sat Oct  4 21:26:02 2014 MESRATI Nada
*/

#include <stdlib.h>

int     my_strncmp(char *s1, char *s2, int n);
int	my_strlen(char *str);

char	*my_strstr(char *str, char* to_find)
{
  int	i;

  i = 0;
  if (str == NULL || to_find == NULL)
    return ("null");
  while (str[i])
    {
      if(str[i] == to_find[0])
	if (my_strncmp(to_find, &str[i], my_strlen(to_find)) == 0)
	  return (&str[i]);
      i++;
    }
  return ("null");
}

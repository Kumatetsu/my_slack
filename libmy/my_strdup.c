/*
** my_strdup.c for my_strdup in /home/mesrat_n/piscine/C/Jour07/my_strdup
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Oct  7 08:31:37 2014 MESRATI Nada
** Last update Sun Apr 23 10:29:36 2017 BILLAUD Jean
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int	my_strlnth(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  i += 1;
  return (i);
}

char	*strcopy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);

}

char	*my_strdup(char *str)
{
  char	*new_str;
  new_str = malloc((my_strlnth(str)) * sizeof(char));
  strcopy(new_str, str);
  return (new_str);
}

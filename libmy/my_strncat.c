/*
** my_strcat.c for my_strcat in /home/mesrat_n/piscine/C/Jour04/mesrat_n/my_strcat
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Thu Oct  2 21:11:33 2014 MESRATI Nada
** Last update Sat Oct  4 21:17:43 2014 MESRATI Nada
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int     my_strlen(char  *str);

char	*my_strncat(char *str1, char *str2, int n)
{
  int	j;
  int	i;
  
  for (i = 0, j = my_strlen(str1); i < n ; j++, i++)
    str1[j] = str2[i];
  str1[j] = '\0';
  return (str1);
}

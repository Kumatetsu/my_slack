/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/mesrat_n/piscine/C/Jour07/mesrat_n/my_str_to_wordtab
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Oct  7 09:01:32 2014 MESRATI Nada
** Last update Tue Mar 28 17:37:36 2017 MESRATI Nada
*/
#include <stdlib.h>

int   my_strlen(char *);

int   count_word(char *str, char separe)
{
  int   i;
  int   count;

  i = 0;
  count = 1;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
  {
    while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
      i++;
    if (str[i])
      count++;
  }
      if (str[i])
  i++;
    }
  return (count);
}

char    **my_str_to_wordtab(char *str, char separe)
{
  char    **tab;
  int   i;
  int   j;
  int   k;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(*tab) * ((count_word(str, separe) + 1)))) == NULL)
    return (0);
  while (str[i] == '\t' || str[i] == ' ' || str[i] == separe)
    i++;
  while (str[i])
    {
      if ((tab[j] = malloc(sizeof(**tab) * (my_strlen(str) + 1))) == NULL)
  return (0);
      k = 0;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != separe && str[i])
        tab[j][k++] = str[i++];
      tab[j++][k] = '\0';
      while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
  i++;
    }
  tab[j] = NULL;
  return (tab);
}

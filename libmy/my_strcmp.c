/*
** my_strcmp.c for my_strcmp in /home/mesrat_n/piscine/C/Jour04/mesrat_n/my_strcmp
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Thu Oct  2 17:25:50 2014 MESRATI Nada
** Last update Tue Mar 28 17:35:03 2017 MESRATI Nada
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (-1);
      i++;
    }
  if (s2[i] != '\0')
    return (-1);
  return (0);
}

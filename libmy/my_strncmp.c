/*
** my_strncmp.c for my_strncmp in /home/mesrat_n/piscine/C/Jour04/mesrat_n/my_strncmp
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Thu Oct  2 18:59:17 2014 MESRATI Nada
** Last update Sat Oct  4 19:27:56 2014 MESRATI Nada
*/

int	my_strncmp(char *s1, char *s2, int n)
{ 
  int	i;

  i = 0;
  while (s1[i] != '\0' && i < n)
    {
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (-1);
      i++;
    }
  return (0);
}

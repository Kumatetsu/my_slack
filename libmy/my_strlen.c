/*
** my_strlen.c for my_strlen in /home/mesrat_n/piscine/C/Jour03/mesrat_n/my_strlen
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Thu Oct  2 09:35:16 2014 MESRATI Nada
** Last update Sat Oct  4 21:15:09 2014 MESRATI Nada
*/

int	my_strlen(char	*str)
{
  int	i;
  
  i = 0;
  while (str[i])
      i++;
  return (i);
}

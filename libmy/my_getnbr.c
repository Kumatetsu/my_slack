/*
** my_getnbr.c for my_getnbr in /home/mesrat_n/piscine/C/Jour03/mesrat_n/my_getnbr
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Thu Oct  2 11:07:05 2014 MESRATI Nada
** Last update Wed Apr 26 12:25:42 2017 BILLAUD Jean
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

/*void	my_put_nbr(int n)
{
  char	tab[100];
  int	i;

  i = 0;
  if (n < 0)
    {
      my_putchar('-');
      n = n * -1;
    }
  while (n > 9)
    {
      tab[i] = ((n % 10) + 48);
      n = n / 10;
      i = i + 1;
    }
  if (n < 10)
    tab[i]=(n + 48);
  while(i >= 0)
    {
      my_putchar(tab[i]);
      --i;
    }
    }*/

int	compteur(char *str)
{
  int	i;
  int	sign;

  i = 0;
  sign = 1;
  while(str[i] != ('\0'))
    {
      if (str[i] == '-')
	{
	  sign *= -1;
	  ++i;
	}
      i = i + 1;
    }
  return (sign);
}

int	my_getnbr(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= (':')) || (str[i] == ('/')) || (str[i] < ('.')))
	return (-1);
      if (str[i] < ('0'))
	i = i + 1;
      if ((str[i] >= (':')) || (str[i] < ('+')))
	{
	  res = res * compteur(str);
	  return (res);
	}
      if ((str[i] >= '0') && (str[i] <= '9'))
	{
	  res = res * 10 + (str[i] - 48);
	  i = i + 1;
	}
    }
  res = res * compteur(str);
  return (res);
}

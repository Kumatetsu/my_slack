/*
** my_swap.c for my_swap in /home/mesrat_n/piscine/C/Jour03/mesrat_n/my_swap
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Thu Oct  2 09:27:38 2014 MESRATI Nada
** Last update Sat Oct  4 21:20:22 2014 MESRATI Nada
*/

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}

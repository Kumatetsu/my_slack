/*
** freetab.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 16:59:46 2017 MESRATI Nada
** Last update Tue Mar 28 17:01:39 2017 MESRATI Nada
*/
#include "client.h"


/*
** Cette fonction sert à free tous les éléments d'un tableau
*/
void	freetab(char **tab)
{
  int	i;
  
  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

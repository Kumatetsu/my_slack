/*
** bzero.c for my_slack in /Users/nada/Documents/ETNA/TIC-DVC3/my_slack/client
** 
** Made by MESRATI Nada
** Login   <mesrat_n@etna-alternance.net>
** 
** Started on  Tue Mar 28 16:57:08 2017 MESRATI Nada
** Last update Tue Apr 25 19:49:51 2017 BILLAUD Jean
*/

/**
 ** Met à 0 (octets contenant « \0 ») les n premiers octets du bloc pointé par s.
 ** La fonction bzero existe dans <strings.h> mais je ne pense pas qu'on y a droit.
 **/

void	my_bzero(void *s1, int n)
{
  char	*c;

  c = (char *)s1;
  while (n > 0)
    {
      *c++ = 0;
      n--;
    }
}

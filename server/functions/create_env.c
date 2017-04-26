/*
** create_env.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack/server_nada
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Fri Apr 21 21:25:51 2017 BILLAUD Jean
** Last update Tue Apr 25 20:02:18 2017 BILLAUD Jean
*/

#include "../headers/server.h"

t_env	*create_env(int p)
{
  t_env	*e;

  e = NULL;
  if((e = malloc(sizeof	(*e))) == NULL)
    return NULL;
  e->port = p;
  e->list = NULL;
  e->chan = NULL;
  return (e);
}

void	init_channel(t_env *e)
{
  int	pos;
  char	*name;
  
  pos = 1;
   if ((name = malloc(sizeof (char) * 2)) == NULL)
        return ;
    while (pos <= 9)
        {
            name[0] = pos + '0';
            name[1] = '\0';
           add_elem_chan(&e->chan, my_strdup(name));
            pos++;
          }
    free(name);
}


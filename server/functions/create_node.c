/*
** create_node.c for my_slack in /Volumes/Neku/Projets-Etna/my_slack
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Sat Apr 22 11:34:14 2017 BILLAUD Jean
** Last update Wed Apr 26 18:36:00 2017 BILLAUD Jean
*/

#include "../headers/server.h"

t_node		*create_node(t_user *user)
{
  t_node	*node;

  if ((node = malloc(sizeof (*node))) == NULL)
    return (NULL);
  node->next = NULL;
  node->prev = NULL;
  node->user = user;
  return (node);
}

t_conv		*create_conv(int fd, char *name, char *buf)
{
  t_conv	*conv;

  if ((conv = malloc(sizeof (*conv))) == NULL)
    return(NULL);
  conv->u_fd = fd;
  if (conv->u_name) 
    conv->u_name = my_strdup(name);
  else conv->u_name = my_strdup("unknown");
  conv->conv = my_strdup(buf);
  conv->next = NULL;
  return conv;
}

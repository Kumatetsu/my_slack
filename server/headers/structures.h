/*
** structures.h for my_slack in /home/naej/ETNA/my_slack/server/headers
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:07:53 2017 BILLAUD Jean
** Last update Tue Apr 18 17:00:28 2017 BILLAUD Jean
*/

#ifndef __STRUCTURES_H_
#define __STRUCTURES_H_

typedef struct	s_user		t_user;
typedef struct	s_channel	t_channel;
typedef struct  s_env		t_env;

struct				s_user
{
  char				*login;
  int				cli_addr;
  int       fd;
  t_user			*next;
  t_user			*prev;
};

struct 				s_channel
{
  char				*name;
  t_user			*first;
  t_user			*last;
  t_channel			*next;
  t_channel			*prev;
};

struct				s_env
{
  t_channel			*first;
  t_channel			*last;
  fd_set      fd_write;
  fd_set      fd_read;
};

#endif

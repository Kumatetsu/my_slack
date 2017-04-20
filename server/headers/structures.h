/*
** structures.h for my_slack in /home/naej/ETNA/my_slack/server/headers
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:07:53 2017 BILLAUD Jean
** Last update Thu Apr 20 22:24:04 2017 BILLAUD Jean
*/

#ifndef __STRUCTURES_H_
#define __STRUCTURES_H_
#include <stdio.h>

typedef enum    e_state		t_state;
typedef struct	s_user		t_user;
typedef struct  s_cont_u	t_cont_u;
typedef struct  s_node		t_node;
typedef struct	s_channel	t_channel;
typedef struct  s_cont_c	t_cont_c;
typedef struct  s_env		t_env;

enum				e_state
{
  WAIT = 0,
  CONNECT = 1
};

struct				s_user
{
  char				*login;
  int				state;
  int				cli_addr;
  void				(*f)();
  t_user			*next;
  t_user			*prev;
};

struct				s_cont_u
{
  t_user			*first;
  t_user			*last;
};

struct				s_node
{
  t_node			*next;
  t_node			*prev;
  t_user			*user;
};

struct 				s_channel
{
  char				*name;
  t_node			*first;
  t_node			*last;
  t_channel			*next;
  t_channel			*prev;
};

struct				s_cont_c
{
  t_channel			*first;
  t_channel			*last;
};

struct				s_env
{
  t_cont_c			*chan;
  t_cont_u			*users;
  fd_set      			fd_write;
  fd_set      			fd_read;
  int       			fd_max;
};

#endif

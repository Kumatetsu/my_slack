/*
** structures.h for my_slack in /home/naej/ETNA/my_slack/server/headers
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Wed Apr 12 21:07:53 2017 BILLAUD Jean
** Last update Wed Apr 19 19:49:57 2017 DEBELLEIX Jérémy
*/

#ifndef __STRUCTURES_H_
#define __STRUCTURES_H_

typedef struct	s_user		t_user;
typedef struct	s_channel	t_channel;
typedef struct  s_env		t_env;
typedef struct  s_command       t_command;

struct				s_user
{
  char				*login;
  int				cli_addr;
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
  int       fd_max;
};

struct                          s_command
{
  char  			*input;
  void   			(*f)(t_env*);
};
#endif

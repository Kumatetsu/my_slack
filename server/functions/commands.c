/*
** commands.c for  in /Volumes/SD/ETNA/slack/my_slack/client
**
** Made by DEBELLEIX Jérémy
** Login   <debell_e@etna-alternance.net>
**
** Started on  Wed Apr 19 16:57:49 2017 DEBELLEIX Jérémy
** Last update Thu Apr 20 21:09:22 2017 DEBELLEIX Jérémy
*/

#include 	<stdlib.h>
#include 	<stdio.h>
#include 	<unistd.h>
#include 	<netdb.h>
#include 	<sys/socket.h>
#include 	<arpa/inet.h>
#include        "../headers/structures.h"
#include        "../headers/server.h"

static const t_command    g_tab_commands[] =
  {
    {"quit_channel", &quit_channel},
    // {"exit", &exit},
    {"join", &join},
    // {"direct", &direct},
    {"channel_lists", &channel_list},
    {"commands_list", &command_list},
    {NULL, NULL},
  };

int    get_cmd(char *input, t_env *env)
{
  int  i;

  i = 0;
  while (g_tab_commands[i].input != NULL)
    {
      if (my_strcmp(g_tab_commands[i].input, input) == 0)
	{
	  g_tab_commands[i].f(env);
	  return (1);
	}
      ++i;
    }
  return (0);
}

void        channel_list(t_env *env)
{
  t_channel *tmp;
  char      *chan_name;
  
  tmp = env->first;
  my_putstr("liste des channels :\n");
  while (tmp)
    {
      chan_name = tmp->name;
      my_putstr(chan_name);
      my_putstr("\n");
      tmp = tmp->next;
    }
}

void    command_list(t_env *env)
{
  int	i;
  char  *current_channel;

  i = 0;
  current_chan = get_current_chan(env);
  if (my_strcmp((current_channel, "general") == 0))
    {
      i = 1;
    } 
  my_putstr("Commandes possibles :\n");
  while (g_tab_commands[i].input != NULL)
    {
      my_putstr(g_tab_commands[i].input);
      my_putchar('\n');
      ++i;
    }
}

void		quit_channel(t_env *env)
{
  t_user	current_user;
  t_channel	current_chan;
  t_channel	general;

  current_user = get_current_user(env);
  current_chan = get_current_channel(env);
  general = env->first;
  if (my_strcmp(current_chan, "general") != 0)
    {
      remove_user_from_chan(current_chan, user, 0);
      change_user_channel(current_chan, general, current_user);
    }
}

void		direct()

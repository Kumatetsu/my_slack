/*
** commands.c for  in /Volumes/SD/ETNA/slack/my_slack/client
**
** Made by DEBELLEIX Jérémy
** Login   <debell_e@etna-alternance.net>
**
** Started on  Wed Apr 19 16:57:49 2017 DEBELLEIX Jérémy
** Last update Wed Apr 19 19:50:30 2017 DEBELLEIX Jérémy
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
    // {"exit", &exit},
    // {"quit", &quit},
    // {"join", &join},
    // {"direct", &direct},
    // {"channel_list", &channel_list},
    {"command_list", &command_list},
    {NULL, NULL},
  };

int    check_command(char *input, t_env *env)
{
  int i;

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

void    command_list(t_env *env)
{
  int	i = 0;

  my_putstr("Commandes possibles :\n");
  while (g_tab_commands[i].input != NULL)
    {
      my_putstr(g_tab_commands[i].input);
      my_putchar('\n');
      ++i;
    }
}

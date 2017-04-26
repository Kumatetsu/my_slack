#include "../headers/server.h"

t_srv_cmd	g_serv_tab[] =
  {
    {"/quit", &quit_serv},
    {"/kick", &kick},
    {NULL, NULL}
  };

int		get_serv_cmd(t_env *e, char *buff)
{
  char		**cmd;
  int		i;

  i = -1;
  if (buff[0] != '\0')
    {
      cmd = my_str_to_wordtab(buff, ' ');
      while (g_serv_tab[++i].cmd != NULL
	     && my_strcmp(cmd[0], g_serv_tab[i].cmd));
      if (g_serv_tab[i].cmd != NULL)
	{
	  if(!g_serv_tab[i].fptr_cmd(e, cmd))
	    {
	      freetab(cmd);
	      return (0);
	    }
	}
      show_all_user(e->chan);
      freetab(cmd);
      return (1);
    }
  return (1);
}

int		quit_serv(t_env *e, char **cmd)
{
  char		*msg;
  
  if (tablen(cmd) == 1)
    {
      msg = my_strdup("Le server va s'arrêter, désolé de la gène occasionnée");
      send_msg_to_all(e, msg);
      free_all_users(e);
      free_all_chan(e);
      free(e);
      free(msg);
      return (0);
    }
  return (1);
}


void		send_msg_to_all(t_env *e, char *msg)
{
  t_user	*user;

  user = e->list;
  while (user)
    {
      if(user->fd != 3 && user->fd != 0)
	writing(user->fd, "server", msg);
      user = user->next;
    }
}

int		kick(t_env *e, char **cmd)
{
  int		i;
  char		*msg;
  t_user	*u;
  t_chan	*u_c;
  
  i = 0;
  u = NULL;
  u_c = NULL;
  if (tablen(cmd) == 2)
    {
      i = my_getnbr(cmd[1]);
      if ((u = get_current_user(e->list, i)) == NULL)
	return (1);
      msg = my_strdup("Vous avez été kick\n");
      writing(i, "server", msg);
      free(msg);
      u_c = get_current_chan(e->chan, i);
      if (u_c)
	disconnect_chan(u_c->first, u_c, i);
      my_disconnect(e, i);
    }
  return (1);
}

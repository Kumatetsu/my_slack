/*
** headers.h for my_slack in /home/naej/ETNA/my_slack/server/headers
** 
** Made by BILLAUD Jean
** Login   <billau_j@etna-alternance.net>
** 
** Started on  Thu Apr 13 16:21:13 2017 BILLAUD Jean
** Last update Tue Apr 18 21:51:31 2017 BILLAUD Jean
*/

#ifndef		__SERVER_H_
#define		__SERVER_H_


/*
** Libmy
*/
void	my_putchar(char c);
void	my_putstr(char *c);
void	my_put_nbr(int n);
void	my_aff_tab(int tab[], int len);
int	my_getnbr(char *str);
int	my_isneg(int n);
void	my_strlen(char *str);
int	my_putnbr_base(int nbr, char *base);
char	*my_strcat(char *str1, char *str2);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *str);
char	*my_strncat(char *str1, char *str2, int n);
int     my_strncmp(char *s1, char *s2, int n);
char    *my_strncpy(char *dest, char *src, int n);
char    *my_strstr(char *str, char* to_find);
int   	count_word(char *str, char separe);
char    **my_str_to_wordtab(char *str, char separe);
void    my_swap(int *a, int *b);

/*
** Construct
*/

t_env		*create_env();
t_user		*create_user(char *login, int cli_addr);
t_channel	*create_channel(char *cli_name);


/*
** add to construct
*/

void		add_channel_to_env(t_env *env, t_channel *chan);
void		add_user_to_chan(t_channel *chan, t_user *user);

/*
** move structs
*/

void		change_user_channel(t_channel *chan1, t_channel *chan2, t_user *user);
void		remove_user_from_chan(t_channel *channel, t_user *user, int quit);


/*
** free structs
*/

void		free_user(t_user *user);
void		free_channel(t_channel *channel);
void		free_env(t_env *env);

/*
** Server functions
*/

int		init_server();
t_env		*init_env();
void		my_serv(int listener, t_env *env);
void		accept_cli(int listener, t_env *env);
void		notify_new_user(t_channel *chan);
void		ask_user_name(t_channel *chan);
#endif

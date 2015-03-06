/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 03:06:09 by achazal           #+#    #+#             */
/*   Updated: 2015/03/06 03:06:10 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include <sys/param.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>
# include <pwd.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <curses.h>
# define MIN_W 10
# define BYPASS struct	termios
# define IS_REG(m) ((m & 0170000) == 0100000)

typedef struct		s_params
{
	char			**av;
	int				ac;
	char			*v_term;
	char			buf[2048];
	struct termios	term;
	char			r_char[4];
	int				print;
	tcflag_t		old_term;
	BYPASS			*oldterm;
	int				c_pos_x;
	int				c_pos_y;
	int				l_count;
	int				col_count;
	int				max_size;
}					t_params;

typedef struct		s_str
{
	char			*str;
	char			*tmp;
	struct s_str	*next;
	struct s_str	*past;
}					t_str;

typedef struct		s_env
{
	char			**env;
	pid_t			pid;
	char			*input;
	int				ac;
	char			**av;
	char			**paths;
	char			*pwd;
	char			*oldpwd;
	char			*binpath;
	char			*home;
	char			*name;
	char			*path;
	t_params		*p;
	char			*str;
	size_t			index;
	size_t			max;
	t_str			*histo;
	t_str			*phisto;
	pid_t			cpid;
	char			*name_shell;
	char			*name_process;
}					t_env;

char				**ft_dup_environ(char **environ);
int					ft_fork(t_env *shell);
void				ft_parse_input(t_env *shell);
int					ft_setenv(t_env *shell);
int					ft_unsetenv(t_env *shell);
void				ft_exit(t_env *shell);
void				ft_exec_bin(t_env *shell);
char				*ft_get_envhome(char **env);
int					ft_cd(t_env *shell);
void				ft_error_2char(char *str, char *str2);
int					ft_unsetenv(t_env *shell);
int					ft_setenv(t_env *shell);
int					ft_arrows(t_env *e, char *inputs);
char				*ft_chardup(char c);
int					ft_clear_input(t_env *e);
void				ft_clean_histo(t_env *e);
void				ft_update_input(t_env *e);
void				ft_endline(t_env *e);
void				ft_cursor_to_end(t_env *e);
int					ft_process_delete(t_env *e);
int					ft_process_back_delete(t_env *e);
int					ft_clear(t_env *e, char *inputs);
t_env				*ft_get_env(char **envp);
int					ft_clean_env(t_env *e);
int					ft_quit(t_env *e, char *inputs);
int					ft_delete(t_env *e, char *inputs);
int					ft_get_inputs(t_env *e);
void				ft_lststr_add(t_str **lst, t_str *new);
t_str				*ft_lststr_new(char *str);
int					ft_process_char(t_env *e, char *inputs);
int					ft_putc(int c);
void				ft_put_histo(t_env *e);
void				ft_goleft(t_env *e);
void				ft_goright(t_env *e);
int					ft_namematch(char *name, char *var);
void				ft_free_strarray(char ***array);
char				**ft_get_env_addr(t_env *shell, char *name);
int					ft_value_exist(t_env *shell, char *name);
void				ft_set_env_value(t_env *shell, char *name, char *value);
void				ft_copy_env_value(t_env *shell, char *src, char *dst);
void				ft_swap_env_value(t_env *shell, char *src, char *dst);
char				**ft_get_env_addr(t_env *shell, char *name);
char				*ft_get_env_value(t_env *shell, char *name);
int					ft_namematch(char *name, char *var);
int					ft_value_exist(t_env *shell, char *name);
void				ft_arrows2(t_env *e, char kind);
void				ft_special(t_env *e, int kind);
void				ft_set_env_value(t_env *shell, char *name, char *value);
char				*ft_linkpath(char *s1, char *s2, char c);
t_params			*ft_get_params(void);
char				**ft_parse_args(t_env *shell, char *input);
char				*ft_update(t_env *shell, char *elem, char *str,
									char *error);
char				*ft_rel_pwd(t_env *shell, char *path);
t_env				*ft_call_env(t_env **shell);
char				*ft_redup(char **str);
void				ft_init_signals(void);
int					ft_reboot_input(t_env *shell);
BYPASS				*sing_oldterm(BYPASS *term);
BYPASS				*sing_newterm(BYPASS *term);
void				ft_exit_properly(void);

#endif

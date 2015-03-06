/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:37:42 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 21:37:42 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"
#include <stdlib.h>

static char			**ft_get_envpath(t_env *shell)
{
	char			*path_line;
	char			**path;

	if (!(path_line = ft_get_env_value(shell, "PATH")))
	{
		path_line = ft_strdup(shell->path);
		ft_set_env_value(shell, "PATH", path_line);
	}
	path = NULL;
	if (path_line)
	{
		path = ft_strsplit(path_line, ':');
		free(path_line);
	}
	return (path);
}

static void			ft_launch(t_env *shell)
{
	char			**inputs;
	char			**ptr;

	if (!(inputs = ft_strsplit(shell->str, ';')))
		return ;
	if (shell->str)
	{
		free(shell->str);
		shell->str = NULL;
	}
	ptr = inputs;
	while (ptr && *ptr)
	{
		shell->str = *ptr++;
		shell->paths = ft_get_envpath(shell);
		ft_parse_input(shell);
		ft_free_strarray(&shell->paths);
	}
	ft_free_strarray(&inputs);
	shell->str = NULL;
}

int					ft_reboot_input(t_env *shell)
{
	int				value;

	while ((value = ft_get_inputs(shell)))
	{
		if (value == 0)
			ft_exit(shell);
		if (shell->str && *shell->str)
			ft_launch(shell);
		if (!(ft_clean_env(shell)))
			break ;
	}
	return (0);
}

int					main(int ac, char **av, char **envp)
{
	t_env			*shell;
	BYPASS			ptr;

	tcgetattr(0, &ptr);
	sing_oldterm(&ptr);
	if (!(shell = ft_get_env(envp)))
		ft_exit_properly(-1);
	ft_call_env(&shell);
	ft_init_signals();
	shell->name_shell = ft_strdup("shell");
	shell->name_process = ft_strdup("test");
	tputs(tgetstr("ve", (char **)(&shell->p->buf)), 1, ft_putc);
	tputs(tgetstr("vs", (char **)(&shell->p->buf)), 1, ft_putc);
	ft_reboot_input(shell);
	tcsetattr(0, TCSANOW, sing_oldterm(NULL));
	return (0);
	(void)ac;
	(void)av;
}

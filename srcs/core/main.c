/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:48:01 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:48:05 by ade-bonn         ###   ########.fr       */
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
	// if (ft_strlen(inputs) > 2 && inputs[0] == ';' && inputs[1])
	// {
	// 	free()
	// }
	
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

int					ft_reboot_imput(t_env *shell)
{
	int				value;

	// ft_init_signals();
	while ((value = ft_get_inputs(shell)))
	{
		if (value == 0)
			ft_exit(shell);
		if (shell->str && *shell->str)
			ft_launch(shell);
		if (!(ft_clean_env(shell)))
			break ;
	}
	// exit(0);
	return (0);
}

static int			ft_minishell(char **envp)
{
	t_env			*shell;

	if (!(shell = ft_get_env(envp)))
		return (0);
	ft_call_env(&shell);
	ft_init_signals();
	shell->name_shell = ft_strdup("shell");
	shell->name_process = ft_strdup("test");
	tputs(tgetstr("ve", (char **)(&shell->p->buf)), 1, ft_putc);
	tputs(tgetstr("vs", (char **)(&shell->p->buf)), 1, ft_putc);
	ft_reboot_imput(shell);
	// while ((value = ft_get_inputs(shell)))
	// {
	// 	if (value == 0)
	// 		ft_exit(shell);
	// 	if (shell->str && *shell->str)
	// 		ft_launch(shell);
	// 	if (!(ft_clean_env(shell)))
	// 		break ;
	// }
	return (0);
	envp++;
	// ft_launch(NULL);
}

int					main(int ac, char **av, char **envp)
{
	int				ret;

	(void)ac;
	(void)av;
	ret = ft_minishell(envp);
	system("leaks ft_minishell1");// > info/leaks.info");
	// system("cat info/leaks.info");
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:47:36 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:47:39 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

static void	ft_print_environ(t_env *shell)
{
	int		i;

	if (shell->env)
	{
		i = 0;
		while (shell->env[i])
		{
			ft_putstr(shell->env[i]);
			ft_putstr("\n");
			++i;
		}
	}
}

static int	ft_count_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		++i;
	return (i);
}

static int	ft_commandmatch(char *name, char *test)
{
	while (*name && *name == *test)
	{
		name++;
		test++;
	}
	if (!*name && !*test)
		return (1);
	return (0);
}

// void		ft_putargs(char **array)
// {
// 	char	**ptr;

// 	ptr = array;
// 	ft_putstr("Arguments are : ");
// 	while (ptr && *ptr)
// 	{
// 		write(1, "\"", 1);
// 		ft_putstr(*ptr++);
// 		write(1, "\" ", 2);
// 	}
// 	write(1, "\n", 1);
// }

void		ft_parse_input(t_env *shell)
{
	if (*shell->str)
	{
		shell->av = ft_parse_args(shell, shell->str);
		// ft_putargs(shell->av);
		if ((shell->ac = ft_count_arg(shell->av)))
		{
			if (ft_commandmatch("env", shell->av[0]))
				ft_print_environ(shell);
			else if (ft_commandmatch("setenv", shell->av[0]))
				ft_setenv(shell);
			else if (ft_commandmatch("unsetenv", shell->av[0]))
				ft_unsetenv(shell);
			else if (ft_commandmatch("exit", shell->av[0]))
				ft_exit(shell);
			else if (ft_commandmatch("cd", shell->av[0]))
				ft_cd(shell);
			else
				ft_exec_bin(shell);
		}
		if (shell->av)
			ft_free_strarray(&shell->av);
	}
}

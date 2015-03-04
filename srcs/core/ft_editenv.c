/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:27:07 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 13:27:48 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

static void	ft_remove_from_env(t_env *shell, int pos, int size)
{
	char	**ne;
	char	**ptr;
	char	**penv;

	if (!(ne = (char **)malloc(sizeof(char *) * size + 1)))
		return ;
	ptr = ne;
	penv = shell->env;
	while (size--)
	{
		if (pos-- == 0)
			free(*penv++);
		*ptr++ = *penv++;
	}
	*ptr = '\0';
	free(shell->env);
	shell->env = ne;
}

static void	ft_unset_from_env(t_env *shell)
{
	int		line_to_remove;
	int		i;

	i = 0;
	line_to_remove = -1;
	while (shell->env[i])
	{
		if (ft_namematch(shell->av[1], shell->env[i]))
			line_to_remove = i;
		++i;
	}
	if (line_to_remove != i)
		ft_remove_from_env(shell, line_to_remove, i);
}

static int	ft_got_space(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			return (1);
		str++;
	}
	return (0);
}

int			ft_setenv(t_env *shell)
{
	if (shell->ac == 3)
	{
		if (ft_got_space(shell->av[1]))
			ft_error_2char("setenv: not valid in this context: ", shell->av[1]);
		else if (ft_get_env_addr(shell, shell->av[1]))
			ft_set_env_value(shell, shell->av[1], shell->av[2]);
	}
	else
		ft_putstr("setenv: wrong usage: setenv [var] [value]\n");
	return (0);
}

int			ft_unsetenv(t_env *shell)
{
	if (shell->ac == 2)
	{
		if (ft_got_space(shell->av[1]))
			ft_error_2char("unsetenv: not valid in this context: ",\
								shell->av[1]);
		else if (ft_get_env_addr(shell, shell->av[1]))
			ft_unset_from_env(shell);
		else
			ft_error_2char("unsetenv: unknown variable: ", shell->av[1]);
	}
	else
		ft_putstr("unsetenv: wrong usage: unsetenv [var]\n");
	return (0);
}

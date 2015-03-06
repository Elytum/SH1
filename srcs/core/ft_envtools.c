/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envtools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:35:39 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 21:35:40 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

char		**ft_get_env_addr(t_env *shell, char *name)
{
	char **ptr;

	ptr = shell->env;
	while (*ptr)
	{
		if (ft_namematch(name, *ptr))
			return (ptr);
		ptr++;
	}
	return (NULL);
}

char		*ft_get_env_value(t_env *shell, char *name)
{
	char **ptr;

	ptr = shell->env;
	while (*ptr)
	{
		if (ft_namematch(name, *ptr))
			return (ft_strdup(ft_strchr(*ptr, '=') + 1));
		ptr++;
	}
	return (NULL);
}

int			ft_namematch(char *name, char *var)
{
	while (*name && ft_toupper(*name) == ft_toupper(*var))
	{
		name++;
		var++;
	}
	if (*var == '=')
		return (1);
	return (0);
}

int			ft_value_exist(t_env *shell, char *name)
{
	char	**ptr;

	ptr = shell->env;
	while (*ptr)
	{
		if (ft_namematch(name, *ptr) && *(*ptr + ft_strlen(name) + 2))
			return (1);
		ptr++;
	}
	return (0);
}

void		ft_exit(t_env *shell)
{
	int		i;
	int		ret;

	if (shell->ac > 2)
	{
		write(1, "exit: too many arguments\n", 25);
		return ;
	}
	if (shell->ac == 1)
		ret = 0;
	else
		ret = ft_atoi(shell->av[1]);
	i = 0;
	while (shell->env[i])
		free(shell->env[i++]);
	if ((shell)->env)
		free(shell->env);
	i = 0;
	while (shell->av[i])
		free(shell->av[i++]);
	if (shell->av)
		free(shell->av);
	shell->pid = 0;
	ft_exit_properly(ret);
}

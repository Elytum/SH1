/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envtools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:27:07 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 13:27:48 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

static void	ft_add_env_value(t_env *shell, char *name, char *value)
{
	size_t	len;
	char	**nenv;
	char	**ptr;
	char	**pnenv;

	ptr = shell->env;
	len = 0;
	while (*ptr++)
		len++;
	if (!(nenv = (char **)malloc(sizeof(char *) * (len + 2))))
		return ;
	ptr = shell->env;
	pnenv = nenv;
	while (*ptr)
		*pnenv++ = *ptr++;
	*pnenv++ = ft_linkpath(name, value, '=');
	*pnenv = NULL;
	free(shell->env);
	shell->env = nenv;
	return ;
}

void		ft_set_env_value(t_env *shell, char *name, char *value)
{
	char	**ptr;
	int		len;

	if (ft_get_env_addr(shell, name))
	{
		len = ft_strlen(name);
		ptr = ft_get_env_addr(shell, name);
		if (*ptr)
			free(*ptr);
		if (!(*ptr = (char *)malloc(sizeof(char) * len + ft_strlen(value) + 2)))
			return ;
		ft_strcpy(*ptr, name);
		ft_strcpy(*ptr + len++, "=");
		ft_strcpy(*ptr + len++, value);
		*(*ptr + len + ft_strlen(value)) = '\0';
	}
	else
		ft_add_env_value(shell, name, value);
}

void		ft_copy_env_value(t_env *shell, char *src, char *dst)
{
	char	*tmp;

	if (!(tmp = ft_get_env_value(shell, src)))
		return ;
	ft_set_env_value(shell, dst, tmp);
	free(tmp);
}

void		ft_swap_env_value(t_env *shell, char *src, char *dst)
{
	char	*srccpy;
	char	*dstcpy;

	if (!(srccpy = ft_get_env_value(shell, src)))
		return ;
	if (!(dstcpy = ft_get_env_value(shell, dst)))
	{
		free(srccpy);
		return ;
	}
	ft_set_env_value(shell, dst, srccpy);
	ft_set_env_value(shell, src, dstcpy);
	free(srccpy);
	free(dstcpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:26:24 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 13:26:58 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

char	*ft_update(t_env *shell, char *elem, char *str, char *error)
{
	char *path;

	if ((path = ft_get_env_value(shell, elem)) && access(path, F_OK) == 0)
		return (path);
	free(path);
	if ((path = ft_strdup(str)) && access(path, F_OK) == 0)
	{
		ft_set_env_value(shell, elem, path);
		return (path);
	}
	ft_putstr(error);
	free(path);
	return (NULL);
}

char	*ft_rel_pwd(t_env *shell, char *path)
{
	char	*pwd;
	char	*tmp;

	if (!(pwd = ft_get_env_value(shell, "PWD")))
		pwd = getcwd(NULL, 0);
	if (pwd)
	{
		if (!(tmp = (char *)malloc(sizeof(char) *
			(ft_strlen(pwd) + ft_strlen(path) + 2))))
			return (NULL);
		ft_strcpy(tmp, pwd);
		*(tmp + ft_strlen(pwd)) = '/';
		ft_strcpy(tmp + ft_strlen(pwd) + 1, path);
		free(pwd);
		pwd = tmp;
	}
	return (pwd);
}

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

static int	ft_cd_less(t_env *shell)
{
	char	*pwd;
	char	*old;

	if (!(pwd = ft_get_env_value(shell, "PWD")))
	{
		if (!(pwd = shell->pwd))
			pwd = getcwd(NULL, 0);
	}
	if (!(old = ft_get_env_value(shell, "OLDPWD")))
		old = shell->oldpwd;
	if (old && !access(old, F_OK))
	{
		ft_set_env_value(shell, "PWD", old);
		ft_set_env_value(shell, "OLDPWD", pwd);
		chdir(old);
	}
	else
		ft_putstr(" cd: << OLDPWD >> undefined\n");
	free(pwd);
	free(old);
	return (0);
}

static int	ft_cd_home(t_env *shell)
{
	char	*path;

	if ((path = ft_update(shell, "HOME", shell->home,
							" cd: << HOME >> undefined\n\n")))
	{
		ft_set_env_value(shell, "PWD", path);
		chdir(path);
		free(shell->pwd);
		shell->pwd = path;
		return (1);
	}
	return (0);
}

static int	ft_cd_normal(t_env *shell, char *path)
{
	char	*tmp;

	if (access(path, F_OK) == 0)
	{
		chdir(path);
		ft_copy_env_value(shell, "PWD", "OLDPWD");
		tmp = getcwd(NULL, 0);
		ft_set_env_value(shell, "PWD", tmp);
		free(shell->pwd);
		shell->pwd = tmp;
		return (1);
	}
	return (0);
}

static int	ft_cd_double(t_env *shell)
{
	char	*ptr;
	char	*pwd;
	char	*tmp;
	int		v;

	if (!(pwd = ft_get_env_value(shell, "PWD")))
		pwd = ft_strdup(shell->pwd);
	if (!(ptr = ft_strstr(pwd, shell->av[1])))
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putstr(shell->av[1]);
		ft_putchar('\n');
		return (0);
	}
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(pwd +
		ft_strlen(shell->av[2]) - ft_strlen(shell->av[1]))))))
		return (0);
	ft_strncpy(tmp, pwd, ptr - pwd);
	ft_strcpy(tmp + (ptr - pwd), shell->av[2]);
	ft_strcpy(tmp + (ptr - pwd) + ft_strlen(shell->av[2]),
				ptr + ft_strlen(shell->av[1]));
	free(pwd);
	v = ft_cd_normal(shell, tmp);
	free(tmp);
	return (v);
}

int			ft_cd(t_env *shell)
{
	char	*path;
	int		i;

	i = 0;
	if (shell->ac == 1 || (shell->ac == 2 &&
				(shell->av[1][0] == '~' && !shell->av[1][1])))
		return (ft_cd_home(shell));
	if (shell->ac == 3)
		return (ft_cd_double(shell));
	if (shell->ac == 2 && shell->av[1])
	{
		if (shell->av[1][0] == '.' && !shell->av[1][1])
			return (0);
		if (shell->av[1][0] == '-' && !shell->av[1][1])
			return (ft_cd_less(shell));
		path = (shell->av[1][0] && shell->av[1][0] != '/')
			? ft_rel_pwd(shell, shell->av[1]) : ft_strdup(shell->av[1]);
		if (!ft_cd_normal(shell, path))
			ft_error_2char("cd: no such file or directory: ", shell->av[1]);
		free(path);
		return (1);
	}
	else
		ft_putstr("cd : Invalid usage\n");
	return (0);
}

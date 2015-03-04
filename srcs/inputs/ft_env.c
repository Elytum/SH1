/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:27:30 by achazal           #+#    #+#             */
/*   Updated: 2015/01/22 08:27:30 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

static void		ft_update_shlvl(t_env *e)
{
	char		**shlvl;
	char		*v;

	if ((shlvl = ft_get_env_addr(e, "SHLVL")))
	{
		v = ft_itoa(ft_atoi(*shlvl + 6) + 1);
		ft_set_env_value(e, "SHLVL", v);
		free(v);
	}
	else
		ft_set_env_value(e, "SHLVL", "1");
}

static void		ft_linkpathfree(char **str, char *new, char c)
{
	char		*tmp;

	tmp = ft_linkpath(*str, new, c);
	free(*str);
	*str = tmp;
}

static void		ft_composepath(t_env *shell)
{
	if (shell->path)
		free(shell->path);
	shell->path = NULL;
	if (access("/usr/local/bin", F_OK) == 0)
		ft_linkpathfree(&(shell->path), "/usr/bin", ':');
	if (access("/usr/bin", F_OK) == 0)
		ft_linkpathfree(&(shell->path), "/usr/bin", ':');
	if (access("/bin", F_OK) == 0)
		ft_linkpathfree(&(shell->path), "/bin", ':');
	if (access("/sbin", F_OK) == 0)
		ft_linkpathfree(&(shell->path), "/sbin", ':');
	if (access("/usr/sbin", F_OK) == 0)
		ft_linkpathfree(&(shell->path), "/usr/sbin", ':');
	if (access("/opt/X11/bin", F_OK) == 0)
	// 	ft_linkpathfree(&(shell->path), "/opt/X11/bin", ':');
	// if (access("/usr/texbin", F_OK) == 0)
	// 	ft_linkpathfree(&(shell->path), "/usr/texbin", ':');
	// if (shell->path && *shell->path)
		ft_set_env_value(shell, "PATH", shell->path);
	else
	{
		ft_copy_env_value(shell, "PWD", "HOME");
		free(shell->path);
		shell->path = ft_strdup(shell->pwd);
	}
}

static void		ft_ironshell(t_env *shell)
{
	if (!shell->pwd || !*shell->pwd || access(shell->pwd, F_OK))
	{
		free(shell->pwd);
		shell->pwd = getcwd(NULL, 0);
		ft_set_env_value(shell, "PWD", shell->pwd);
	}
	if (!shell->home || !*shell->home || access(shell->home, F_OK))
	{
		if (access("/nfs", F_OK) == 0)
			ft_set_env_value(shell, "HOME", "/nfs");
		else
			ft_copy_env_value(shell, "PWD", "HOME");
		free(shell->home);
		shell->home = ft_get_env_value(shell, "HOME");
	}
	if (!shell->path || !*shell->path)
		ft_composepath(shell);
}

t_env			*ft_get_env(char **envp)
{
	t_env		*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	e->name = ft_strdup("Shell > ");
	if (!(e->p = ft_get_params()))
		return (NULL);
	if (!(e->str = ft_strdup("")))
		return (NULL);
	e->max = 0;
	e->index = 0;
	if (!(e->histo = (t_str *)ft_memalloc(sizeof(t_str))))
		return (NULL);
	e->env = ft_dup_environ(envp);
	e->pwd = ft_get_env_value(e, "PWD");
	e->home = ft_get_env_value(e, "HOME");
	e->oldpwd = ft_get_env_value(e, "OLDPWD");
	ft_ironshell(e);
	ft_update_shlvl(e);
	e->binpath = NULL;
	return (e);
}

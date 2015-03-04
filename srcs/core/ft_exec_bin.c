/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:36:01 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 21:36:02 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"
#include <sys/stat.h>

static char			ft_isexec(char *path)
{
	struct stat sb;

	if (!stat(path, &sb))
	{
		if (IS_REG(sb.st_mode) && sb.st_mode & 0111)
			return (1);
	}
	return (0);
}

static int			ft_set_binpath(t_env *shell)
{
	int				i;

	i = 0;
	if (shell->path != NULL)
	{
		if (ft_isexec(shell->av[0]))
		{
			shell->binpath = ft_strdup(shell->av[0]);
			return (0);
		}
		while (shell->paths[i] && shell->av[0])
		{
			if ((shell->binpath = ft_linkpath(shell->paths[i++],\
									shell->av[0], '/')))
			{
				if (ft_isexec(shell->binpath))
					return (0);
				free(shell->binpath);
			}
		}
		ft_error_2char("shell: no such file or directory: ", shell->av[0]);
	}
	else
		ft_error_2char("Undefined environment PATH :", shell->av[0]);
	return (-1);
}

static void			ft_wrong_exit2(int sig_num)
{
	if (sig_num == SIGBUS)
		write(1, ": bus error ", 12);
	else if (sig_num == SIGSEGV)
		write(1, ": segmentation fault ", 21);
	else if (sig_num == SIGALRM)
		write(1, ": ti", 4);
	else if (sig_num == SIGXCPU)
		write(1, ": cpu limit exceeded ", 21);
	else if (sig_num == SIGXFSZ)
		write(1, ": size limit exceeded ", 22);
	else if (sig_num == SIGVTALRM)
		write(1, ": virtual time alarm ", 21);
	else if (sig_num == SIGPROF)
		write(1, ": profile signal shell", 22);
	else if (sig_num == SIGUSR1)
		write(1, ": user-defined signal 1 shell", 29);
	else if (sig_num == SIGUSR2)
		write(1, ": user-defined signal 2 shell", 29);
}

void				ft_wrong_exit(char *father, int sig_num, char *son)
{
	if (sig_num == SIGPIPE)
		return ;
	ft_putstr(father);
	if (sig_num == SIGHUP)
		write(1, ": hangup ", 9);
	else if (sig_num == SIGILL)
		write(1, ": illegal hardware instruction ", 31);
	else if (sig_num == SIGTRAP)
		write(1, ": trace trap shell", 18);
	else if (sig_num == SIGABRT)
		write(1, ": abort ", 8);
	else if (sig_num == SIGFPE)
		write(1, ": floating point exception ", 27);
	else if (sig_num == SIGKILL)
		write(1, ": killed ", 9);
	else
		ft_wrong_exit2(sig_num);
	ft_putendl(son);
}

void				ft_exec_bin(t_env *shell)
{
	int				stat_loc;

	if (ft_set_binpath(shell) == 0)
	{
		signal(SIGABRT, ignore);
		shell->cpid = fork();
		if (shell->cpid != -1)
		{
			if (shell->cpid == 0)
				execve(shell->binpath, shell->av, shell->env);
			else
				waitpid(shell->cpid, &stat_loc, 0);
		}
		if (WIFSIGNALED(stat_loc))
			ft_wrong_exit(shell->name_shell,
				WTERMSIG(stat_loc), shell->binpath);
		free(shell->p);
		free(shell->binpath);
		shell->p = ft_get_params();
		shell->cpid = 0;
	}
}

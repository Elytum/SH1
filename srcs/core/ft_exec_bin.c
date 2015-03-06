/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 03:00:40 by achazal           #+#    #+#             */
/*   Updated: 2015/03/06 03:00:41 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"
#include <sys/stat.h>

static void			ft_wrong_exit2(int sig_num)
{
	if (sig_num == SIGBUS)
		write(1, ": bus error ", 12);
	else if (sig_num == SIGSEGV)
		write(1, ": segmentation fault ", 21);
	else if (sig_num == SIGSYS)
		write(1, ": invalid system call ", 22);
	else if (sig_num == SIGALRM)
		write(1, ": timeout ", 10);
	else if (sig_num == SIGSTOP)
		write(1, ": suspended (signal) ", 21);
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
	if (sig_num == SIGPIPE || sig_num == SIGINT)
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
	else if (sig_num == SIGEMT)
		write(1, ": EMT instruction ", 18);
	else if (sig_num == SIGFPE)
		write(1, ": floating point exception ", 27);
	else if (sig_num == SIGKILL)
		write(1, ": killed ", 9);
	else
		ft_wrong_exit2(sig_num);
	ft_putendl(son);
}

static int			ft_set_binpath(t_env *shell)
{
	int				i;

	i = 0;
	if (shell->path != NULL)
	{
		if (access(shell->av[0], X_OK) == 0)
		{
			shell->binpath = ft_strdup(shell->av[0]);
			return (0);
		}
		while (shell->paths[i] && shell->av[0])
		{
			if ((shell->binpath = ft_linkpath(shell->paths[i++],\
									shell->av[0], '/')))
			{
				if (access(shell->binpath, X_OK) == 0)
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

void				ft_exec_bin(t_env *shell)
{
	int				stat_loc;

	if (ft_set_binpath(shell) == 0)
	{
		tcsetattr(0, TCSANOW, sing_oldterm(NULL));
		// tcsetattr(0, 0, sing_oldterm(NULL));
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
		free(shell->binpath);
		shell->cpid = 0;
		tcsetattr(0, 0, sing_newterm(NULL));
	}
}

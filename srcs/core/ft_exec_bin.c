/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:44:47 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/02/15 14:15:17 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"
#include <sys/stat.h>

t_env				*ft_call_env(t_env **shell)
{
	static t_env	*save;

	if (shell && *shell)
	{
		save = *shell;
		return (NULL);
	}
	else
		return (save);
}

static char	ft_isexec(char *path)
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

void ignore( int sig )
{
	(void)sig;
    ft_putstr ("GladOsh : Program aborted : ./loop\n"); // Print a new line
    // This function does nothing except ignore ctrl-c
}

// #include <sys/types.h>
// #include <sys/wait.h>
/*
static void			ft_sigprof(int sig_num)
{ //To handle for real
	ft_putstr("shell: profile signal shell\n");
	exit(0);
	(void)sig_num;
}

static void			ft_sigtrap(int sig_num)
{ //To handle for real
	ft_putstr("shell: trace trap shell\n");
	exit(0);
	(void)sig_num;
}
*/
void				ft_wrong_exit(char *father, int sig_num, char *son)
{
	if (sig_num == SIGPIPE)
		return ;
	ft_putstr(father);
	if (sig_num == SIGHUP)
		write(1, ": hangup ", 9); //INT
	//3 SIGQUIT zsh: quit       ./loop
	else if (sig_num == SIGILL)
		write(1, ": illegal hardware instruction ", 31);
	else if (sig_num == SIGTRAP)
		write(1, ": trace trap shell", 18);
	else if (sig_num == SIGABRT)
		write(1, ": abort ", 8);
	//7 GEMT zsh: EMT instruction  ./loop
	else if (sig_num == SIGFPE)
		write(1, ": floating point exception ", 27);
	else if (sig_num == SIGKILL)
		write(1, ": killed ", 9);
	else if (sig_num == SIGBUS)
		write(1, ": bus error ", 12);
	else if (sig_num == SIGSEGV)
		write(1, ": segmentation fault ", 21);
	//12 SYS zsh: invalid system call  ./loop
	//13 PIPE NULL
	else if (sig_num == SIGALRM)
		write(1, ": ti", 4);
	//15 TERM zsh: terminated  ./loop
	//16 URG NULL ??
	//17 STOP zsh: suspended (signal)  ./loop
	//18 TSTP ??
	//19 CONT ?? NULL
	//20 CHLD ?? NULL
	//21 TTIN zsh: suspended (tty input)  ./loop
	//22 TTOU zsh: suspended (tty output)  ./loop
	//23 GIO ??KILL
	else if (sig_num == SIGXCPU)
		write(1, ": cpu limit exceeded ", 21);
	else if (sig_num == SIGXFSZ)
		write(1, ": size limit exceeded ", 22);
	else if (sig_num == SIGVTALRM)
		write(1, ": virtual time alarm ", 21);
	else if (sig_num == SIGPROF)
		write(1, ": profile signal shell", 22);
	//28 WINCH ??
	//29 INFO ??
	else if (sig_num == SIGUSR1)
		write(1, ": user-defined signal 1 shell", 29);
	else if (sig_num == SIGUSR2)
		write(1, ": user-defined signal 2 shell", 29);
	ft_putendl(son);
}

void				ft_exec_bin(t_env *shell)
{
	int				stat_loc;

	if (ft_set_binpath(shell) == 0)
	{
		// ft_restore_signals(shell);
		// ft_init_signals();
		// signal(SIGINT, ignore);
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
			ft_wrong_exit(shell->name_shell, WTERMSIG(stat_loc), shell->binpath);

		free(shell->p);
		free(shell->binpath);
		shell->p = ft_get_params();
		shell->cpid = 0;
		// ft_init_signals();
	}
}

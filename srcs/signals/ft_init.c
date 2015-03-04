/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:39:53 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 21:39:55 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

static void			ft_sig_to_reload(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	if (sig_num == SIGINT)
	{
		if (shell->cpid)
		{
			write(0, "^C\n", 3);
			shell->cpid = 0;
		}
		else
		{
			write(1, "\n", 1);
			ft_putstr(shell->name);
			free(shell->str);
			shell->str = ft_strdup("");
			shell->index = 0;
			shell->max = 0;
		}
	}
}

static void			ft_sigterm(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	ft_putstr("\nGladOsh: Did you really try to kill me ? Hehe, no chance !\n");
	free(shell->str);
	shell->str = ft_strdup("");
	shell->index = 0;
	shell->max = 0;
	return ;
	(void)sig_num;
}

static void			ft_sig_to_exit(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	ft_putstr(shell->name_shell);
	if (sig_num == SIGABRT || sig_num == SIGALRM)
		ft_putstr((sig_num == SIGABRT) ? ": abort " : ": ti");
	else if (sig_num == SIGKILL || sig_num == SIGBUS)
		ft_putstr((sig_num == SIGKILL) ? ": killed " : ": bus error ");
	else if (sig_num == SIGFPE)
		ft_putstr(": floating point exception ");
	else if (sig_num == SIGILL)
		ft_putstr(": illegal hardware instruction ");
	else if (sig_num == SIGSEGV)
		ft_putstr(": segmentation fault ");
	else if (sig_num == SIGVTALRM)
		ft_putstr(": virtual time alarm ");
	else if (sig_num == SIGXCPU)
		ft_putstr(": cpu limit exceeded ");
	else if (sig_num == SIGXCPU)
		ft_putstr(": size limit exceeded ");
	ft_putendl(shell->name_shell);
	tcsetattr(0, 0, sing_oldterm(NULL));
	exit(0);
}

static void			ft_sigstop(int sig_num)
{
	ft_putstr("shell: suspended (signal) shell\n");
	exit(0);
	(void)sig_num;
}

void				ft_init_signals(void)
{
	signal(SIGABRT, ft_sig_to_reload);
	signal(SIGALRM, ft_sig_to_exit);
	signal(SIGBUS, ft_sig_to_exit);
	signal(SIGFPE, ft_sig_to_exit);
	signal(SIGHUP, ft_sig_to_exit);
	signal(SIGILL, ft_sig_to_exit);
	signal(SIGINT, ft_sig_to_reload);
	signal(SIGKILL, ft_sig_to_exit);
	signal(SIGPIPE, ft_sig_to_exit);
	signal(SIGSEGV, ft_sig_to_exit);
	signal(SIGSTOP, ft_sigstop);
	signal(SIGTERM, ft_sigterm);
	signal(SIGUSR1, ft_sig_define_user);
	signal(SIGUSR2, ft_sig_define_user);
	signal(SIGPROF, ft_sigprof);
	signal(SIGSYS, ft_sig_to_reload);
	signal(SIGTRAP, ft_sigtrap);
	signal(SIGVTALRM, ft_sig_to_exit);
	signal(SIGXCPU, ft_sig_to_exit);
	signal(SIGXFSZ, ft_sig_to_exit);
}

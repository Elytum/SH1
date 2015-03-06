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

void				ft_sig_to_reload(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	if (sig_num == SIGINT)
	{
		if (!(shell->cpid))
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

void				ft_sigterm(int sig_num)
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

void				ft_sig_to_exit(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	if (!(shell->cpid))
	{
		tcsetattr(0, 0, sing_oldterm(NULL));
		signal(sig_num, SIG_DFL);
		kill(getpid(), sig_num);
	}
}

static void			ft_init_signals2(void)
{
	signal(SIGVTALRM, ft_sig_to_exit);
	signal(SIGPROF, ft_sig_to_exit);
	signal(SIGWINCH, SIG_IGN);
	signal(SIGINFO, SIG_IGN);
	signal(SIGUSR1, ft_sig_to_exit);
	signal(SIGUSR2, ft_sig_to_exit);
}

void				ft_init_signals(void)
{
	signal(SIGHUP, ft_sig_to_exit);
	signal(SIGINT, ft_sig_to_reload);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGILL, ft_sig_to_exit);
	signal(SIGTRAP, ft_sig_to_exit);
	signal(SIGABRT, ft_sig_to_exit);
	signal(SIGEMT, ft_sig_to_exit);
	signal(SIGFPE, ft_sig_to_exit);
	signal(SIGKILL, ft_sig_to_exit);
	signal(SIGBUS, ft_sig_to_exit);
	signal(SIGSEGV, ft_sig_to_exit);
	signal(SIGSYS, ft_sig_to_exit);
	signal(SIGPIPE, ft_sig_to_exit);
	signal(SIGALRM, ft_sig_to_exit);
	signal(SIGTERM, SIG_IGN);
	signal(SIGURG, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGIO, SIG_IGN);
	signal(SIGXCPU, ft_sig_to_exit);
	signal(SIGXFSZ, ft_sig_to_exit);
	ft_init_signals2();
}

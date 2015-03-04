#include "../../includes/ft_sh1.h"
#include <stdio.h>

static void			ft_sig_to_reload(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	if (sig_num == SIGINT)
	{
		if (shell->cpid)
		{
			write(0, "^F\n", 3);
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
	// else if (sig_num == SIGSYS)
	else
		write(1, "COUCOU C'EST MOI\n", 17);
}

static void			ft_sigterm(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	ft_putstr("\nGladOsh: Did you really try to kill me ? Hehe, no chance !\n");
	// shell->index = 0;
	// shell->max = 0;
	// ft_putstr(shell->name);
	free(shell->str);
	shell->str = ft_strdup("");
	shell->index = 0;
	shell->max = 0;
	// ft_clean_env(shell);
	// ft_reboot_imput(shell);
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
	exit(0);
}

static void			ft_sigstop(int sig_num)
{ //To handle for real
	ft_putstr("shell: suspended (signal) shell\n");
	exit(0);
	(void)sig_num;
}

static void			ft_sig_define_user(int sig_num)
{ //To handle for real
	if (sig_num == SIGUSR1)
		ft_putstr("shell: user-defined signal 1 shell\n");
	else if (sig_num == SIGUSR2)
		ft_putstr("shell: user-defined signal 2 shell\n");
	exit(0);
}

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

void				ft_init_signals(void)
{
	signal(SIGABRT, ft_sig_to_reload);
	signal(SIGALRM, ft_sig_to_exit);
	signal(SIGBUS, ft_sig_to_exit);
	// signal(SIGCHLD, ft_sigchld); // Son died // ZSH PRINT NOTHING WITHOUT EXEC
	// signal(SIGCONT, ft_sigcont); // Wake up (fg) // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGFPE, ft_sig_to_exit);
	signal(SIGHUP, ft_sig_to_exit);
	signal(SIGILL, ft_sig_to_exit);
	signal(SIGINT, ft_sig_to_reload);
	signal(SIGKILL, ft_sig_to_exit);
	signal(SIGPIPE, ft_sig_to_exit);
	// signal(SIGQUIT, ft_sigquit); // UNKNOWN // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGSEGV, ft_sig_to_exit);
	signal(SIGSTOP, ft_sigstop); // Stop (fg)
	signal(SIGTERM, ft_sigterm);
	// signal(SIGTSTP, ft_sigtstp); // Break (fg) // ZSH PRINT NOTHING WITHOUT EXEC
	// signal(SIGTTIN, ft_sig_define_user); // Not precise (Input relatif) // ZSH PRINT NOTHING WITHOUT EXEC
	// signal(SIGTTOU, ft_sig_define_user); // Not precise (Input relatif) // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGUSR1, ft_sig_define_user); // UNKNOWN
	signal(SIGUSR2, ft_sig_define_user); // UNKNOWN
	// signal(SIGPOLL, ft_sigpoll); // ... // Can't be used with kill
	signal(SIGPROF, ft_sigprof); // Pthread -> Plus tard
	signal(SIGSYS, ft_sig_to_reload);
	signal(SIGTRAP, ft_sigtrap); // Do not set
	// signal(SIGURG, ft_sigurg); // Server, may not have to be set // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGVTALRM, ft_sig_to_exit); // Time related
	signal(SIGXCPU, ft_sig_to_exit); // Time out
	signal(SIGXFSZ, ft_sig_to_exit); // Max file size
}
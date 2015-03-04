/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:39:53 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 21:39:55 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

BYPASS				*sing_oldterm(BYPASS *term)
{
	static BYPASS	*old;

	if (term != NULL)
		old = term;
	return (old);
}

void				ft_sig_define_user(int sig_num)
{
	if (sig_num == SIGUSR1)
		ft_putstr("shell: user-defined signal 1 shell\n");
	else if (sig_num == SIGUSR2)
		ft_putstr("shell: user-defined signal 2 shell\n");
	exit(0);
}

void				ft_sigprof(int sig_num)
{
	ft_putstr("shell: profile signal shell\n");
	exit(0);
	(void)sig_num;
}

void				ft_sigtrap(int sig_num)
{
	ft_putstr("shell: trace trap shell\n");
	exit(0);
	(void)sig_num;
}

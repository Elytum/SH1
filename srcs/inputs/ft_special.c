/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:16:08 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/02/06 14:16:09 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

static void	ft_home(t_env *e)
{
	if (!e->index)
		tputs(tgetstr("bl", (char **)(&e->p->buf)), 1, ft_putc);
	else
		while (e->index)
			ft_goleft(e);
}

static void	ft_end(t_env *e)
{
	if (e->index == e->max)
		tputs(tgetstr("bl", (char **)(&e->p->buf)), 1, ft_putc);
	else
		while (e->index != e->max)
			ft_goright(e);
}

void		ft_special(t_env *e, int kind)
{
	if (kind == 70)
		ft_end(e);
	else if (kind == 72)
		ft_home(e);
}
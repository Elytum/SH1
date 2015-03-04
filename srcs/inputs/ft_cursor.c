/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:08:45 by achazal           #+#    #+#             */
/*   Updated: 2015/01/22 08:23:47 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

// arthur

void		ft_update_imput(t_env *e)
{
	int len;

	tputs(e->str, 1, ft_putc);
	len = e->max - e->index;
	while (len--)
		tputs(tgetstr("le", (char **)(&e->p->buf)), 1, ft_putc);
}

void		ft_endline(t_env *e)
{
	while (e->index < e->max)
		ft_goright(e);
	tputs("\n", 1, ft_putc);
}


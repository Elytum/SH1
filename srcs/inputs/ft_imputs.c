/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:35:52 by achazal           #+#    #+#             */
/*   Updated: 2015/01/22 08:35:53 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

//	arthur

int			ft_quit(t_env *e, char *inputs)
{
	if (inputs[0] == 3)
		return (0);
	else if (inputs[0] == 10)
	{
		if (e->histo->str)
			free(e->histo->str);
		e->histo->str = ft_strdup(e->str);
		ft_endline(e);
		return (1);
	}
	else if (inputs[0] == 4)
	{
		if (e->histo->str)
			free(e->histo->str);
		e->histo->str = ft_strdup(e->str);
		ft_endline(e);
		return (0);
	}
	return (0);
}

int			ft_delete(t_env *e, char *inputs)
{
	if (inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 51 &&
	(inputs[3] == 126 && inputs[4] == 0))
	{
		ft_process_back_delete(e);
		return (1);
	}
	if (inputs[0] == 127 && inputs[1] == 0 && inputs[2] == 0)
	{
		ft_process_delete(e);
		return (1);
	}
	return (0);
}

static void	ft_lstr_inputsinit(t_env *e)
{
	if (!(e->histo))
		ft_lststr_add(&(e->histo), ft_lststr_new(""));
	e->phisto = e->histo;
	if (e->phisto->str && (*(e->phisto->str)))
	{
		ft_lststr_add(&(e->histo), ft_lststr_new(""));
		e->phisto = e->histo;
	}
}

static int	ft_manage_inputs(t_env *e, char *inputs)
{
	int		value;

	if ((inputs[0] == 4 || inputs[0] == 10) &&
		inputs[1] == 0 && inputs[2] == 0 && inputs[3] == 0 &&
		inputs[4] == 0 && inputs[5] == 0 && inputs[6] == 0)
		return (ft_quit(e, inputs));
	else if (!ft_delete(e, inputs))
		if (!ft_arrows(e, inputs))
			if (!ft_clear(e, inputs))
				if (ft_isprint(inputs[0]) || inputs[0] == 9)
					if ((value = ft_process_char(e, inputs)) != 2)
						return (value);
	return (-1);
}

int			ft_get_inputs(t_env *e)
{
	char	inputs[7];
	int		value;

	ft_bzero(inputs, 7);
	ft_clean_histo(e);
	ft_lstr_inputsinit(e);
	tputs(e->name, 1, ft_putc);
	while ((read(0, inputs, 7)) != EOF)
	{
		// printf("Imputs : %i %i %i %i %i %i %i\n", inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6]);
		if ((value = ft_manage_inputs(e, inputs)) >= 0)
			return (value);
		ft_bzero(inputs, 7);
	}
	ft_endline(e);
	return (0);
}

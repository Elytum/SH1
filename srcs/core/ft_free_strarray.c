/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:22:52 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/14 14:25:35 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

// done

void	ft_free_strarray(char ***array)
{
	char **ptr;

	ptr = *array;
	while (*ptr)
	{
		free(*ptr++);
	}
	free(*array);
}

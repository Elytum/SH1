/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:36:12 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 21:36:12 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

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

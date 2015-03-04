/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 09:35:42 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 09:35:49 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	char	*upper_str;
	int		i;

	i = 0;
	upper_str = NULL;
	if (str)
	{
		while (str[i])
			++i;
		upper_str = malloc((i + 1) * sizeof(char));
		if (upper_str == NULL)
			return (NULL);
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				upper_str[i] = 'A' + (str[i] - 'a');
			else
				upper_str[i] = str[i];
			++i;
		}
		upper_str[i] = 0;
	}
	return (upper_str);
}

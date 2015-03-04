/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tabtosp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:47:48 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 10:47:51 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup_tabtosp(const char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\t')
			dest[i] = ' ';
		else
			dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

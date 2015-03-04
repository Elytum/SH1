/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 16:49:21 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/09 16:49:22 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	len;
	int	i;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}

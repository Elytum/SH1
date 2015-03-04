/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 09:55:24 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 09:55:29 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while ((s1[index] == s2[index]) && s1[index] != '\0' && s2[index] != '\0')
		index = index + 1;
	return ((s1[index] - s2[index]));
}

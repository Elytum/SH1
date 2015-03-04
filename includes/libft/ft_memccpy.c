/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 09:43:31 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/04 09:43:33 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dst;
	const char		*src = s2;

	dst = s1;
	while (n--)
	{
		*dst++ = *src;
		if (*src == (unsigned char)c)
			return (dst);
		src++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:32:03 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/10 14:32:04 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len_s2;

	len_s2 = ft_strlen(s2);
	if (!*s2)
		return ((char*)s1);
	while (*s1 && len_s2 <= n--)
	{
		if (!ft_memcmp(s1++, s2, len_s2))
			return ((char*)s1 - 1);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 16:58:29 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/09 16:58:30 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	char	*tmp_dst;

	if (s == NULL)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dst == NULL)
		return (NULL);
	tmp_dst = dst;
	while (*s != '\0')
	{
		*tmp_dst = (*f)(*s);
		tmp_dst++;
		s++;
	}
	*tmp_dst = '\0';
	return (dst);
}

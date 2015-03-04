/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:35:59 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/09 17:36:04 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*tmp;

	if (s && f)
	{
		j = ft_strlen((char*)s);
		i = 0;
		tmp = (char*)malloc(j * sizeof(tmp));
		while (s[i] != '\0')
		{
			tmp[i] = f(s[i], i);
			i++;
		}
		return (tmp);
	}
	return (NULL);
}

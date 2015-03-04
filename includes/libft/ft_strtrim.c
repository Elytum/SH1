/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:07:53 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/11 14:08:10 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int len_space;
	int len;
	int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	len_space = 0;
	i = 0;
	while (s[i] && ft_isspace(s[i]))
	{
		len_space++;
		i++;
	}
	while (len >= 0 && ft_isspace(s[len]))
		len--;
	return (ft_strsub(s, i, len - len_space + 1));
}

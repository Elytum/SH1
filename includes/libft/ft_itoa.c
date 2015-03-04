/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:52:35 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/14 14:56:46 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_n_count(int n, int i)
{
	while (n > 9 || n < 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		len;
	int		nbr;
	char	*str2;
	int		i;
	char	*str;

	len = (n < 0) ? 2 : 1;
	nbr = n;
	i = ft_n_count(n, len);
	str2 = ft_strnew(i + 1);
	while (i > 0)
	{
		if (n >= 0)
			str2[i - 1] = ((char)((nbr % 10) + 48));
		if (n < 0 && i >= 2)
			str2[i - 2] = ((char)(48 - (nbr % 10)));
		i--;
		nbr /= 10;
	}
	if (n < 0)
		str2[i] = '-';
	str = ft_strnew(ft_n_count(n, len) + 1);
	ft_strcpy(str, str2);
	free(str2);
	return (str);
}

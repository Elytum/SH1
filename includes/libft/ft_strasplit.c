/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strasplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:22:52 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/02/15 14:30:24 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbr_words(char const *s, char *c)
{
	int			i;
	int			nbr;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(c,s[i]))
			i++;
		while (s[i] && !ft_strchr(c, s[i]))
			i++;
		if (s[i] != '\0' || !ft_strchr(c, s[i - 1]))
			nbr++;
	}
	return (nbr);
}

char			**ft_strasplit(char const *s, char *c)
{
	char		**str;
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_nbr_words(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (i < len)
	{
		j = 0;
		while (*s && ft_strchr(c, *s))
			s = s + 1;
		while (*(s + j) && !ft_strchr(c, *(s + j)))
			j++;
		*(str++) = ft_strsub(s, 0, j);
		s = s + j;
		i++;
	}
	*str = NULL;
	return (str - len);
}

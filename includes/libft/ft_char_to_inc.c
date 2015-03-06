/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_inc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 03:07:19 by achazal           #+#    #+#             */
/*   Updated: 2015/03/06 03:07:20 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_char_to_inc(char **tab)
{
	char	**new_tab;
	int		len;

	len = 0;
	new_tab = NULL;
	while (tab[len])
		++len;
	if (len != 0)
	{
		new_tab = (char **)malloc((len + 2) * sizeof(char *));
		if (new_tab != NULL)
		{
			len = 0;
			while (tab[len])
			{
				new_tab[len] = ft_strdup(tab[len]);
				free(tab[len]);
				++len;
			}
			new_tab[len + 1] = 0;
			free(tab);
		}
	}
	return (new_tab);
}

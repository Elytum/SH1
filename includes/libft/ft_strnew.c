/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:00:01 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/06 23:27:11 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *tmp;

	tmp = (void *)ft_memalloc(size + 1);
	if (tmp == NULL)
		return (0);
	return (tmp);
}

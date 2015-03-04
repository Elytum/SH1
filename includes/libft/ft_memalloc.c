/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:19:33 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/08 14:20:44 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *tmp;

	tmp = (char*)malloc(sizeof(char) * size);
	if (tmp != NULL)
	{
		ft_bzero(tmp, size);
		return ((void*)tmp);
	}
	return (NULL);
}

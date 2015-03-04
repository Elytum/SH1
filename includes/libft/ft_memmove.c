/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 09:43:47 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/04 09:44:07 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *tmp;

	tmp = (char*)malloc(sizeof(char) * len);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	free (tmp);
	return (dst);
}

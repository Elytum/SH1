/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:08:45 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/06 10:08:47 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar_fd(char c, int fd)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	return (write(fd, &chr, 1));
}

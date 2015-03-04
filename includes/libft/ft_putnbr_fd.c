/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_df.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:20:51 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/11 13:20:52 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		nbr = -n;
	}
	if (nbr / 10)
		i += ft_putnbr_fd(nbr / 10, fd);
	i += ft_putchar_fd(nbr % 10 + '0', fd);
	return (i);
}

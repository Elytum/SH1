/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charmanage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:38:18 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 21:38:19 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

char		*ft_chardup(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

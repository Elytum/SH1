/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrmanage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:30:20 by achazal           #+#    #+#             */
/*   Updated: 2015/01/22 08:30:20 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

// arthur

void		ft_lststr_add(t_str **lst, t_str *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	(*lst)->past = new;
	*lst = new;
}

t_str		*ft_lststr_new(char *str)
{
	t_str *tmp;

	tmp = (t_str *)ft_memalloc(sizeof(t_str));
	tmp->str = ft_strdup(str);
	tmp->past = NULL;
	tmp->next = NULL;
	return (tmp);
}

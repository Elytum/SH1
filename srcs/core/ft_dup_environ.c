/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:35:18 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 21:35:21 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sh1.h"

t_params			*ft_get_params(void)
{
	t_params		*p;

	if (!(p = (t_params *)ft_memalloc(sizeof(t_params))))
		ft_exit_properly(-1);
	p->c_pos_x = 0;
	p->c_pos_y = 0;
	p->print = 0;
	if (tgetent(p->buf, p->v_term) < 1)
		ft_exit_properly(-1);
	tcgetattr(0, &p->term);
	p->term.c_lflag &= ~(ICANON);
	p->term.c_lflag &= ~(ECHO);
	p->term.c_cc[VMIN] = 1;
	p->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &p->term) == -1)
		ft_exit_properly(-1);
	p->max_size = 1;
	p->col_count = 1;
	sing_newterm(&p->term);
	return (p);
}

int					ft_clean_env(t_env *e)
{
	if (e->str)
	{
		free(e->str);
		e->str = NULL;
	}
	if (!(e->str = ft_strdup("")))
		return (0);
	e->index = 0;
	e->max = 0;
	return (1);
}

BYPASS				*sing_oldterm(BYPASS *term)
{
	static BYPASS	*old;

	if (term != NULL)
		old = term;
	return (old);
}

BYPASS				*sing_newterm(BYPASS *term)
{
	static BYPASS	*new;

	if (term != NULL)
		new = term;
	return (new);
}

char				**ft_dup_environ(char **environ)
{
	char			**ptr;
	char			**bis;
	char			**ptr2;
	size_t			i;

	i = 0;
	ptr = environ;
	while (*ptr++)
		i++;
	if (!(bis = (char **)malloc((i + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	ptr = environ;
	ptr2 = bis;
	while (*ptr)
	{
		*ptr2++ = ft_strdup(*ptr++);
		++i;
	}
	*ptr2 = NULL;
	return (bis);
}

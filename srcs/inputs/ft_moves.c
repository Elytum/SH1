#include "../../includes/ft_sh1.h"

// arthur

static void		ft_trucbidule(t_env *e)
{
	char		tmp[2];

	if (((ft_strlen(e->name) + e->index) % tgetnum("co"))
			!= tgetnum("co") - 1)
		tputs(tgetstr("nd", (char **)(&e->p->buf)), 1, ft_putc);
	else
	{
		tmp[1] = '\0';
		tmp[0] = e->str[e->index];
		tputs(tmp, 1, ft_putc);
		tmp[0] = e->str[e->index + 1];
		tputs(tmp, 1, ft_putc);
		tputs(tgetstr("le", (char **)(&e->p->buf)), 1, ft_putc);
	}
}

static int		sizeoftab(t_env *e, int i)
{
	int			size;
	size_t		pos;
	size_t		sizecol;
	char		*ptr;
	char		*end;

	size = 8;
	sizecol = tgetnum("co");
	pos = (ft_strlen(e->name) + e->index) % sizecol;
	ptr = e->str;
	end = e->str + i;
	while (ptr != end)
	{
		if (*ptr == '\t')
		{
			pos += size;
			size = 8;
		}
		else
		{
			pos += 1;
			if ((--size) == 0)
				size = 8;
		}
		// if (pos + size > sizecol) // Si on est sur le point de depasser
		// 	size = sizecol - pos; // On ajsute la tab sur le reste de la ligne
		// else if (pos > sizecol) // Si on a depassé
		// {
		// 	pos = 0; // On se remet au debut
		// 	size = 8; // Et on reset la taille de la tab
		// }
		ptr++;
	}
	return (size);
}

void			ft_goleft(t_env *e)
{
	int			n;

	if (e->str[e->index - 1] == '\t')
		n = sizeoftab(e, e->index - 1);//n = 8;
	else
		n = 1;
	while (n-- > 0)
		tputs(tgetstr("le", (char **)(&e->p->buf)), 1, ft_putc);
	e->index--;
}

void			ft_goright(t_env *e)
{
	int			n;
	
	if (e->str[e->index] == '\t')
		n = sizeoftab(e, e->index);//n = 8;
	else
		n = 1;
	while (n-- > 0)
		ft_trucbidule(e);
	e->index++;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2020/03/21 16:07:26 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_links(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	ft_printf("\n                ");
	while (++i <= e->nb_room)
		ft_printf("[%i]", i);
	ft_printf("\n");
	i = -1;
	while (++i <= e->nb_room)
	{
		ft_printf("%10.10s [%i]:", e->names[i]->name, i);
		j = -1;
		while (++j <= e->nb_room)
			ft_printf("  %i", e->links[i][j]);
		if (e->names[i]->startend == 1)
			ft_printf("  START");
		else if (e->names[i]->startend == 2)
			ft_printf("  END");
		ft_printf("\n");
	}
}

int		free_list(t_memlist *mem)
{
	t_memlist	*f;

	while (mem->n)
	{
		f = mem;
		mem = mem->n;
		free(f);
	}
	free(mem);
	return (1);
}

int		read_map(t_env *e, char **inst)
{
	t_memlist	*mem;
	t_memlist	*first;
	
	mem = li_lstnew();
	first = mem;
	while (ari_get_next_line(e->fd, inst) == 1 && *inst != NULL)
	{
		if (*inst[0] == '#' &&
		ft_strcmp(*inst, "##start\n") && ft_strcmp(*inst, "##end\n"))
			;
		else if (e->nb_ants == -1)
		{
			if (li_atoi(*inst, &e->nb_ants, '\n') == 0 || e->nb_ants <= 0)
				return (0);
		}
		else if (!e->links && !ft_strchr(ft_strcut(*inst, ' ', 0), '-'))
		{
			if (!fill_names(inst, &mem, first) && free_list(first))
				return (0);
		}
		else if (ft_strchr(*inst, '-'))
		{
			if (!fill_links(e, inst, first, mem))
				return (0);
		}
		else
			return (0);
		free(*inst);
	}
	if (e->links != NULL)
		print_links(e);
	return (e->links ? 1 : 0);
}

t_env		*parsing(char *pathname)
{
	t_env	*e;
	char	**inst;

	e = NULL;
	inst = NULL;
	e = ft_memalloc(sizeof(t_env));
	e->nb_ants = -1;
	e->nb_room = 0;
	e->names = NULL;
	e->links = NULL;
	inst = ft_memalloc(sizeof(char*));
	if (pathname)
		e->fd = open(pathname, FLAGS);
	else
		e->fd = STDIN_FILENO;
	if (read_map(e, inst) == 0)
		error(&e, inst, 1);
	return (e);
}

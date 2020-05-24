/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2020/03/15 16:25:17 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*char	**copy_tab(char **tab, char **argv, int argc, int i)
{
	int		j;

	j = 0;
	if ((tab = malloc(sizeof(*tab) * (argc - i + 1))) == NULL)
		return (NULL);
	while (i + j < argc)
	{
		if ((tab[j] = ft_strdup(argv[i + j])) == NULL)
			return (NULL);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
*/

int		free_mat(int **mat, int nb_room)
{
	int		i;

	i = 0;
	while (i <= nb_room)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	return (1);
}

int		free_tab(t_names **tab, int nb_room)
{
	int		i;

	i = 0;
	while (i <= nb_room)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

int		error(t_env **e, char **inst, int err)
{
	if (err)
		write(2, "Error\n", 6);
	if (*e)
	{
		if ((*e)->names)
			free_tab((*e)->names, (*e)->nb_room);
		if ((*e)->links)
			free_mat((*e)->links, (*e)->nb_room);
		free(*e);
		*e = NULL;
	}
	if (inst)
	{
		if (*inst)
		{	
			free(*inst);
			*inst = NULL;
		}
		free(inst);
		inst = NULL;
	}
	return (err);
}

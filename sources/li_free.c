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
int		free_mat(int **mat)
{
	int		i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	return (1);
}

int		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

int		error(t_env *e, char **inst, int err)
{
	if (err)
		write(2, "Error\n", 6);
	if (e)
		free(e);
	if (inst)
	{
		if (*inst)
			free(*inst);
		free(inst);
	}
	return (err);
}

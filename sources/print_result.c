/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/27 03:31:56 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	order_tab(int **path, int lenght_path)
{
	int		i;
	int		ordered;
	int		tmp;

	ordered = 0;
	while (ordered == 0)
	{
		ordered = 1;
		i = -1;
		while (++i < lenght_path - 1)
		{
			if (path[0][i] > path[0][i + 1])
			{
				tmp = path[0][i];
				path[0][i] = path[0][i + 1];
				path[0][i + 1] = tmp;
				ordered = 0; 
			}
		}
	}
}

int		print_ant(t_in *in, t_ant *ants)
{
	int		i;
	int		j;
	int		turn;

	turn = 0;
	i = -1;
	while (i < in->ant_size)
	{
		i = -1;
		while (++i < in->ant_size && ants[i].turn <= turn)
		{
			j = -1;
			while (ants[i].in != -1 && in->matrix[ants[i].in][++j] != ants[i].path)
				;
			if (ants[i].in != -1)
				ft_printf("L%i-id%i/%i/%i ", i, j, ants[i].path, ants[i].turn);
			ants[i].in = (j < in->room_count - 1 ? j : -1);
		}
		turn++;
		ft_printf("\n");
		i = -1;
		while (++i < in->ant_size && ants[i].in == -1)
			;
	}
	ft_printf("NBR LINE : %i\n", turn);
	return (1);
}

int		init_ant(t_in *in, int **path, int lenght_path)
{
	t_ant	*ants;
	int		i;
	int		j;
	int		turn;
	int		ant;

	ant = in->ant_size;
	ants = malloc(sizeof(t_ant) * in->ant_size);
	while (ant--)
	{
		i = 0;
		while (i < lenght_path - 1 &&
			path[0][i] + path[1][i] > path[0][i + 1] + path[1][i + 1])
			{
				//ft_printf("num%i, nbr%i\n", path[0][i], path[1][i]);
				i++;
			}
		ft_printf("num%i, nbr%i,\n", path[0][i], path[1][i]);
		path[1][i]++;
	}
	j = 0;
	turn = 0;
	ft_printf("lenght - 1 = %i\n", lenght_path - 1);
	while (path[1][0])
	{
		i = -1;
		
		while (++i < lenght_path && path[1][i])
		{
			path[1][i]--;
			ft_printf("%i, %i  ", i, path[1][i]);
			ants[j].in = 0;
			ants[j].turn = turn;
			ants[j].path = i + 2;
			ants[j++].length = path[0][i];
		}
		turn++;
		ft_printf("\n");
	}
	print_ant(in, ants);
	return (1);
}

int		init_path(t_in *in)
{
	int		i;
	int		j;
	int		**path;

	j = 0;
	i = -1;
	while (++i < in->room_count)
		j += (in->matrix[0][i] ? 1 : 0);
	path = malloc(sizeof(int*) * 2);
	path[0] = malloc(sizeof(int) * j);
	path[1] = malloc(sizeof(int) * j);	
	i = -1;
	j = 0;
	while (++i < in->room_count)
	{
		if (in->matrix[0][i] > 1 && !(path[1][j] = 0))
			path[0][j++] = in->matrix[i][0];
	}
	order_tab(path, j);
	init_ant(in, path, j);
	return (1);
}

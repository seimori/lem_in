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

//int		mix_path(t_in *in, int room_in, int tmp)
//{

//}

int		previous_room(t_in *in, int room_in, int nb_path)
{
	int		tmp;

	while (in->oriented[room_in][0] != -3)
	{
		tmp = 0;
		while (++tmp < (in->room_count - 1) * 2)
		{
			if (in->oriented[room_in][tmp] == -1)
				mix_path(in, in->oriented[room_in][0], tmp);
		}
		ft_printf("room_in %i\n", room_in);
		in->oriented[room_in][in->oriented[room_in][0]] = -1;
		in->oriented[in->oriented[room_in][0]][room_in] =
			(in->oriented[in->oriented[room_in][0]][room_in] == -1 ? -1 : 0);
		tmp = (in->oriented[room_in - 1][0] < 0 ? 0 : in->oriented[room_in - 1][0]);
		if (room_in % 2 == 0 && tmp)
		{
			in->matrix[room_in / 2][tmp / 2] = 0;
			in->matrix[tmp / 2][room_in / 2] = nb_path + 1;
			if (tmp && in->oriented[room_in][tmp - 1] == 1)
				in->oriented[room_in][tmp - 1] = 0;
		}
		room_in = in->oriented[room_in][0];
		print_oriented(in);
		print_links(in);
	}
	return (room_in);
}

void	retrace_path(t_in *in, t_queue *to_visit)
{
	int		room_in;
	int		nb_path;
	int		tmp;
	int		len;

	print_oriented(in);
	room_in = to_visit->in;
	len = (to_visit->score + 1) / 2;
	nb_path = 1;
	tmp = -1;
	while (++tmp < in->room_count)
		nb_path = (in->matrix[0][tmp] > nb_path ? in->matrix[0][tmp] : nb_path);
	in->oriented[(in->room_count - 1) * 2 - 1][room_in] = -1;
	in->oriented[room_in][(in->room_count - 1) * 2 - 1] = 0;
	in->matrix[in->room_count - 1][room_in / 2] = 0;
	in->matrix[room_in / 2][in->room_count - 1] = nb_path + 1;
	room_in = previous_room(in, room_in, nb_path);
	tmp = 0;
	while (++tmp < (in->room_count - 1) * 2)
		in->oriented[tmp][0] = (in->oriented[tmp][0] == -1 ? in->oriented[tmp][0] : 0);
	in->oriented[room_in][0] = -1;
	in->oriented[0][room_in] = 0;
	in->matrix[(room_in + 1) / 2][0] = len;
	in->matrix[0][(room_in + 1) / 2] = nb_path + 1;
}

t_queue		*explore_room(t_in *in, t_queue **to_visit)
{
	int			j;
	t_queue		*end_visit;
	t_queue		*tmp;

	j = 0;
	while (++j <= (in->room_count - 2) * 2)
	{
		if ((in->oriented[(*to_visit)->in][j] == 1 ||
			in->oriented[(*to_visit)->in][j] == -1) && in->oriented[j][0] == 0)
		{
			end_visit = *to_visit;
			while (in->oriented[(*to_visit)->in][j] == 1 && end_visit->next != NULL)
				end_visit = end_visit->next;
			tmp = (*to_visit)->next;
			if ((end_visit->next = malloc(sizeof(t_queue))) == NULL)
				return (NULL);
			end_visit->next->in = j;
			end_visit->next->score = (*to_visit)->score + in->oriented[(*to_visit)->in][j];
			end_visit->next->next = (in->oriented[(*to_visit)->in][j] == -1 ? tmp : NULL);
			in->oriented[j][0] = ((*to_visit)->in == 0 ? -3 : (*to_visit)->in);
			//in->oriented[j][(*to_visit)->in] = -((*to_visit)->score + in->oriented[(*to_visit)->in][j]);
		}
	}
	end_visit = (*to_visit)->next;
	free(*to_visit);
	*to_visit = NULL;
	return (end_visit);
}

int		oriented_bfs(t_in *in)
{
	t_queue     *to_visit;
	t_queue		*tmp;

	if ((to_visit = malloc(sizeof(t_queue))) == NULL)
		return (0);
	to_visit->in = 0;
	to_visit->score = 2;
	to_visit->next = NULL;
	ft_printf("BFS\n");
	print_oriented(in);
	while (to_visit)
	{
		if (in->oriented[to_visit->in][(in->room_count - 1) * 2 - 1])
		{
			retrace_path(in, to_visit);
			while (to_visit)
			{
				tmp = to_visit;
				to_visit = to_visit->next;
				free(tmp);
				tmp = NULL;
			}
			print_links(in);
			return (1);
		}
		to_visit = explore_room(in, &to_visit);
	}
	ft_printf("NO PATH\n");
	return (0);
}
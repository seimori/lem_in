/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:50:32 by seimori           #+#    #+#             */
/*   Updated: 2020/06/27 18:32:35 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_in			*lock_path(t_in *in, t_room *path)
{
	in = make_path_directed(in, path);
	in = duplicate_path_intermediates(in, path);
	return (in);
}

t_room			**suurballe(t_in *in, t_room **paths)
{
	int			path_id;

	path_id = 0;
	paths[0] = dijkstra(in);
	in = lock_path(in, paths[path_id]);
	return (paths);
}
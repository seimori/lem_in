/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/06/02 19:16:32 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int 		main(int argc, char **argv)
{
	t_env	*e;
	t_in 	*in;
	t_room 	**paths;

	if (argc == 2)
		e = parsing(argv[1]);
	else
		e = parsing(NULL);
	if (e->links == NULL)
		return (0);
	in = env_to_in(e);
	if (in->end_room == NULL)
		return (0);
	in->max_paths = get_max_paths(in);
	if (in->max_paths <= 0)
		return (0);
	paths = get_paths(in);
	paths = ant_calculus(in, paths);
	print_ants(in, paths);
	visualizer(in);
	free(paths);
	free(in);
	return (0);
}
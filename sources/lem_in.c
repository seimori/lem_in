/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/16 15:02:25 by seimori          ###   ########.fr       */
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
	in = env_to_in(e);
	// in = get_test_case();
	in->max_paths = get_max_paths(in);
	paths = get_paths(in);
	paths = ant_calculus(in, paths);
	print_ants(in, paths);
	free(paths);
	free(in);
	return (0);
}
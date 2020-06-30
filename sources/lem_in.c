/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/06/30 17:28:54 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// t_room          **initialize_paths(t_in *in, int max_paths, t_room **paths)
// {
//     t_room      *paths[max_paths];

//     // paths = (t_room**)ft_memalloc(sizeof(t_room*) * max_paths);
//     paths[0] = in->room;
//     return (paths);
// }

t_in			*algorithm_and_print(t_in *in)
{
	t_room		*paths[in->max_paths];

	// paths = initialize_paths(in, in->max_paths);
	suurballe(in, paths);
	ant_calculus(in, paths);
	ft_printf("%s", in->map_buf);
	print_ants(in, paths);
	return (in);
}

int		main(int argc, char **argv)
{
	t_in	*in;

	if (argc == 2)
		in = parsing(argv[1]);
	else
		in = parsing(NULL);
	if (in == NULL)
	{
		sleep(1);
		return (0);
	}
	in->max_paths = get_max_paths(in);
	if (in->max_paths <= 0)
	{
		sleep(1);
		return (0);
	}
	in = algorithm_and_print(in);
	// free(paths);
	// li_free(&in, NULL, 0);
	sleep(1);
	return (0);
}

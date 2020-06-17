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

int		main(int argc, char **argv)
{
	t_in	*in;
	t_room	**paths;

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
	paths = get_paths(in);
	paths = ant_calculus(in, paths);
	ft_printf("%s", in->map_buf);
	print_ants(in, paths);
	free(paths);
	li_free(&in, NULL, 0);
	sleep(1);
	return (0);
}

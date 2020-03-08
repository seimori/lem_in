/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/08 02:36:13 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int            print_ant(t_room *first, t_room *path)
{
    if (!path->trail)
        return (0);
    print_ant(first, path->trail);
    ft_printf("L%d-%d\n", 1, path->id);
    if (path == first)
		ft_printf("L%d-%d\n", 1, 0);
	return (1);
}

int             main(void)
{
    t_in        *in;
    t_room      **paths;

    in = get_test_case();
    in->max_paths = get_max_paths(in);
    paths = get_paths(in);
    paths = ant_calculus(in, paths);
    print_ant(paths[0], paths[0]);
    print_ant(paths[1], paths[1]);
    free(paths);
    free(in);
}
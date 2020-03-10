/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/10 15:32:31 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int             main(void)
{
    t_in        *in;
    t_room      **paths;

    in = get_test_case();
    in->max_paths = get_max_paths(in);
    paths = get_paths(in);
    paths = ant_calculus(in, paths);
    print_ants(in, paths);
    free(paths);
    free(in);
}
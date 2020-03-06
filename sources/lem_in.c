/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:46:59 by seimori           #+#    #+#             */
/*   Updated: 2020/03/06 17:14:17 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int             main(void)
{
    t_in        *in;
    t_room      **paths;
    int         *ant_list;

    in = get_test_case();
    in->max_paths = get_max_paths(in);
    paths = get_paths(in);
    ant_list = ant_calculus(in, paths);
    free(ant_list);
    free(paths);
    free(in);
}
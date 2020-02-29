/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:22:42 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/28 13:18:51 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_percent(t_arg arg, t_specs *specs)
{
	(void)arg;
	specs->arg_len = 1;
	if (!(specs->flags & MINUS))
		specs->spaces_len = print_width(specs);
	ft_putchar('%');
	return (specs->arg_len + specs->spaces_len);
}

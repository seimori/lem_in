/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:59:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 17:31:28 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_precision(t_specs *specs)
{
	int			hash_offset;

	hash_offset = 0;
	if (specs->flags & HASH && !(specs->is_zero) && specs->flags & MINUS
			&& (specs->conversion == 'x' || specs->conversion == 'X'))
		hash_offset = 2;
	while (specs->arg_len < specs->precision + hash_offset)
	{
		specs->arg_len++;
		ft_putchar('0');
	}
	return (specs->arg_len);
}

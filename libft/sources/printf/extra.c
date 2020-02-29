/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:49:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/03 18:17:01 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		print_bits(int bits, int size)
{
	while (size >= 0)
	{
		if (bits & 1 << size)
			ft_putnbr(1);
		else
			ft_putnbr(0);
		size--;
	}
}

void		print_specs(t_specs *specs)
{
	ft_putstr("flags: ");
	print_bits(specs->flags, 4);
	ft_putchar('\n');
	ft_putstr("width: ");
	ft_putnbr(specs->width);
	ft_putchar('\n');
	ft_putstr("precision: ");
	ft_putnbr(specs->precision);
	ft_putchar('\n');
	ft_putstr("lengthmodifier: ");
	print_bits(specs->lengthmodifier, 4);
	ft_putchar('\n');
	ft_putstr("conversion: ");
	ft_putchar(specs->conversion);
	ft_putchar('\n');
	ft_putstr("typeindex: ");
	ft_putnbr(specs->typeindex);
	ft_putchar('\n');
	ft_putchar('\n');
}

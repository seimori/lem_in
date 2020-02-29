/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:53:42 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 18:38:37 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define FPN_G_COUNT_INIT 0
#define ROUND_UP 0.4999999999999999

unsigned int	print_fpn(unsigned long long n, t_specs *specs)
{
	if (n >= 10)
		print_fpn(n / 10, specs);
	if (specs->arg_len == 0)
	{
		if (n > 1)
			specs->dot_left += 1;
		specs->arg_len = ft_putnbr_ull(specs->dot_left, specs);
		specs->arg_len += print_dot(specs);
	}
	else
		ft_putchar(n % 10 + '0');
	specs->arg_len++;
	return (specs->arg_len - 1);
}

unsigned int	assemble_fpn(long double f, t_specs *specs)
{
	unsigned int		count;
	int					precision;

	if ((count = fpn_special_cases(f, specs)))
		return (count);
	specs->precision = get_precision(specs->precision);
	if (!(specs->lengthmodifier & BIG_L))
		f = (double)f;
	count = print_sign_fpn(f, specs);
	if (f < 0 || (1.0 / f == -1.0 / 0.0))
		f = -f;
	specs->dot_left = (unsigned long long)f;
	f -= (unsigned long long)f;
	f += 1;
	precision = specs->precision;
	while (precision--)
		f *= 10;
	specs->arg_len = 0;
	count += print_fpn((unsigned long long)(f + ROUND_UP),
			specs);
	specs->arg_len = count;
	return (specs->arg_len);
}

int				print_float(t_arg arg, t_specs *specs)
{
	int			count;

	count = 0;
	if (specs->lengthmodifier & BIG_L)
	{
		if (!(specs->flags & MINUS))
			count = print_options_fpn(arg.big_l_f, specs);
		count += assemble_fpn(arg.big_l_f, specs);
	}
	else
	{
		if (!(specs->flags & MINUS))
			count = print_options_fpn((long double)arg.lf, specs);
		count += assemble_fpn((long double)arg.lf, specs);
	}
	return (count);
}

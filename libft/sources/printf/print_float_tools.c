/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 00:01:51 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 17:53:37 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

unsigned int	fpn_special_cases(long double f, t_specs *specs)
{
	if (f >= 1.0 / 0.0)
	{
		ft_putstr("inf");
		specs->special |= INF;
		return (3);
	}
	if (f <= -1.0 / 0.0)
	{
		ft_putstr("-inf");
		specs->special |= N_INF;
		return (4);
	}
	if (f != f)
	{
		ft_putstr("nan");
		specs->special |= NAN;
		return (3);
	}
	return (0);
}

unsigned int	ft_putnbr_ull(unsigned long long n, t_specs *specs)
{
	if (n >= 10)
		ft_putnbr_ull(n / 10, specs);
	ft_putchar(n % 10 + '0');
	specs->arg_len++;
	return (specs->arg_len);
}

unsigned int	print_dot(t_specs *specs)
{
	if (specs->precision > 0 || specs->flags & HASH)
	{
		ft_putchar('.');
		return (1);
	}
	else
		return (0);
}

int				get_precision(int precision)
{
	if (precision < 0)
		return (6);
	else
		return (precision);
}

int				print_sign_fpn(long double f, t_specs *specs)
{
	if (!(specs->flags & ZERO))
	{
		if (f < 0 || (1.0 / f == -1.0 / 0.0))
			ft_putchar('-');
		else if (specs->flags & PLUS)
			ft_putchar('+');
		else if (specs->flags & SPACE)
			ft_putchar(' ');
		else
			return (0);
		return (1);
	}
	else if (f < 0 || (1.0 / f == -1.0 / 0.0)
			|| specs->flags & PLUS
			|| specs->flags & SPACE)
		return (1);
	else
		return (0);
}

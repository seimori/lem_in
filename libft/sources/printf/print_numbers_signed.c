/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers_signed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:26:47 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 23:27:14 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

unsigned long long		get_ui_n(long long int n, t_specs *specs)
{
	unsigned long long		ui_n;

	if (n < 0)
	{
		ui_n = -n;
		specs->is_negative = 1;
	}
	else
		ui_n = n;
	return (ui_n);
}

int						print_signed_decimal(long long int n, t_specs *specs)
{
	unsigned long long		ui_n;

	if (specs->lengthmodifier & HH)
		n = (char)n;
	else if (specs->lengthmodifier & H)
		n = (short)n;
	else if (specs->lengthmodifier & L)
		n = (long)n;
	else if (specs->lengthmodifier & LL)
		n = (long long)n;
	else
		n = (int)n;
	ui_n = get_ui_n(n, specs);
	if (ui_n >= 10)
	{
		specs->arg_len++;
		print_signed_decimal(ui_n / 10, specs);
	}
	else
		specs->arg_len = print_options(specs);
	ft_putchar(ui_n % 10 + '0');
	return (specs->arg_len);
}

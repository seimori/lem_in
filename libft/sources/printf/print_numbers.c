/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:49:03 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 23:27:15 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		print_unsigned_decimal(unsigned long long ui_n, t_specs *specs)
{
	if (specs->lengthmodifier & HH)
		ui_n = (unsigned char)ui_n;
	else if (specs->lengthmodifier & H)
		ui_n = (unsigned short)ui_n;
	else if (specs->lengthmodifier & L)
		ui_n = (unsigned long)ui_n;
	else if (specs->lengthmodifier & LL)
		ui_n = (unsigned long long)ui_n;
	else
		ui_n = (unsigned int)ui_n;
	if (ui_n >= 10)
	{
		specs->arg_len++;
		print_unsigned_decimal(ui_n / 10, specs);
	}
	else
		specs->arg_len = print_options(specs);
	ft_putchar(ui_n % 10 + '0');
	return (specs->arg_len);
}

int		print_octal(unsigned long long ui_n, t_specs *specs)
{
	if (specs->lengthmodifier & HH)
		ui_n = (unsigned char)ui_n;
	else if (specs->lengthmodifier & H)
		ui_n = (unsigned short)ui_n;
	else if (specs->lengthmodifier & L)
		ui_n = (unsigned long)ui_n;
	else if (specs->lengthmodifier & LL)
		ui_n = (unsigned long long)ui_n;
	else
		ui_n = (unsigned int)ui_n;
	if (ui_n >= 8)
	{
		specs->arg_len++;
		print_octal(ui_n / 8, specs);
	}
	else
		specs->arg_len = print_options(specs);
	ft_putchar(ui_n % 8 + '0');
	return (specs->arg_len);
}

int		print_hexadecimal(unsigned long long int ui_n, t_specs *specs)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'a', 'b', 'c', 'd', 'e', 'f'};

	if (specs->lengthmodifier & HH)
		ui_n = (unsigned char)ui_n;
	else if (specs->lengthmodifier & H)
		ui_n = (unsigned short)ui_n;
	else if (specs->lengthmodifier & L)
		ui_n = (unsigned long)ui_n;
	else if (specs->lengthmodifier & LL || specs->conversion == 'p')
		ui_n = (unsigned long long)ui_n;
	else
		ui_n = (unsigned int)ui_n;
	if (ui_n >= 16)
	{
		specs->arg_len++;
		print_hexadecimal(ui_n / 16, specs);
	}
	else
		specs->arg_len = print_options(specs);
	ft_putchar(hexa[ui_n % 16]);
	return (specs->arg_len);
}

int		print_hexadecimal_big(unsigned long long int ui_n, t_specs *specs)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (specs->lengthmodifier & HH)
		ui_n = (unsigned char)ui_n;
	else if (specs->lengthmodifier & H)
		ui_n = (unsigned short)ui_n;
	else if (specs->lengthmodifier & L)
		ui_n = (unsigned long)ui_n;
	else if (specs->lengthmodifier & LL)
		ui_n = (unsigned long long)ui_n;
	else
		ui_n = (unsigned int)ui_n;
	if (ui_n >= 16)
	{
		specs->arg_len++;
		print_hexadecimal_big(ui_n / 16, specs);
	}
	else
		specs->arg_len = print_options(specs);
	ft_putchar(hexa[ui_n % 16]);
	return (specs->arg_len);
}

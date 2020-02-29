/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:27:26 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 15:18:00 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' ||
			c == '+' || c == ' ');
}

int				is_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == '%' ||
			c == 'd' || c == 'i' || c == 'o' || c == 'u' ||
			c == 'x' || c == 'X' || c == 'f');
}

int				is_lengthmodifier(const char *s)
{
	if (ft_strnequ(s, "hh", 2) || ft_strnequ(s, "ll", 2))
		return (2);
	else if (s[0] == 'h' || s[0] == 'l' || s[0] == 'L'
			|| s[0] == 'j' || s[0] == 'z')
		return (1);
	else
		return (0);
}

int				is_hex_or_octal(t_specs *specs)
{
	return (specs->conversion == 'x' || specs->conversion == 'X'
			|| specs->conversion == 'o' || specs->conversion == 'p');
}

int				is_signed(t_specs *specs)
{
	return (specs->conversion == 'd' || specs->conversion == 'i');
}

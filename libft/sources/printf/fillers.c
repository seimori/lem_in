/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:25:29 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 15:35:28 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				fill_flags(const char *s, t_specs *specs)
{
	int			i;

	i = 0;
	while (is_flag(s[i]))
	{
		if (s[i] == '-')
			specs->flags |= MINUS;
		if (s[i] == '+')
			specs->flags |= PLUS;
		if (s[i] == ' ')
			specs->flags |= SPACE;
		if (s[i] == '0')
			specs->flags |= ZERO;
		if (s[i] == '#')
			specs->flags |= HASH;
		i++;
	}
	return (i);
}

int				fill_width(const char *s, t_specs *specs, va_list args)
{
	int			i;
	int			has_wildcard;

	i = 0;
	has_wildcard = 0;
	if (s[i] == '*')
	{
		specs->width = va_arg(args, int);
		if (specs->width < 0)
		{
			specs->flags |= MINUS;
			specs->width = -specs->width;
		}
		i++;
		has_wildcard = 1;
	}
	if (!(ft_isdigit(s[i])))
		return (i);
	while (ft_isdigit(s[i]))
		i++;
	specs->width = ft_antoi(s + has_wildcard, i);
	return (i);
}

int				fill_precision(const char *s, t_specs *specs, va_list args)
{
	int			i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
		{
			specs->precision = va_arg(args, int);
			return (i + 1);
		}
		while (ft_isdigit(s[i]))
			i++;
		specs->precision = ft_antoi(s + 1, i - 1);
	}
	else
		specs->precision = -1;
	return (i);
}

int				fill_lengthmodifier(const char *s, t_specs *specs)
{
	int				i;

	i = 1;
	if (ft_strnequ(s, "hh", 2))
		specs->lengthmodifier |= HH;
	else if (ft_strnequ(s, "ll", 2))
		specs->lengthmodifier |= LL;
	else if (s[0] == 'h')
		specs->lengthmodifier |= H;
	else if (s[0] == 'l' || s[0] == 'j' || s[0] == 'z')
		specs->lengthmodifier |= L;
	else if (s[0] == 'L')
		specs->lengthmodifier |= BIG_L;
	while (is_lengthmodifier(s + i))
		i++;
	if (specs->lengthmodifier > 0)
		return (i);
	else
		return (0);
}

int				fill_conversion(const char *s, t_specs *specs)
{
	if (is_conversion(s[0]))
	{
		specs->conversion = s[0];
		return (1);
	}
	else if (s[0] == 'U')
	{
		specs->conversion = 'd';
		specs->lengthmodifier = 0;
		specs->lengthmodifier |= L;
		return (1);
	}
	return (0);
}

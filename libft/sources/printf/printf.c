/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:48:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 18:47:10 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
**	The repetition of calls in fill_specs are to account for undefined
**	behaviors.
**	Originally, it should be:
**	fill_flags > fill_width > fill_precision > fill_lengthmodifier
**	> fill_conversion
*/

static int		fill_specs(const char *s, t_specs *specs, va_list args)
{
	int			i;

	i = 1;
	i += fill_flags(s + i, specs);
	i += fill_width(s + i, specs, args);
	i += fill_precision(s + i, specs, args);
	i += fill_lengthmodifier(s + i, specs);
	i += fill_width(s + i, specs, args);
	i += fill_flags(s + i, specs);
	i += fill_width(s + i, specs, args);
	i += fill_conversion(s + i, specs);
	specs->typeindex = get_typeindex(specs);
	return (i);
}

static int		print_til_percent(const char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0'
			&& s[i] != '%')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int				ft_vprintf(const char *format, va_list args, t_fp_arg *print
		, t_count *count)
{
	t_specs		*specs;

	while (format[count->format] != '\0')
	{
		count->temp += print_til_percent(format + count->format);
		count->format += count->temp;
		count->print += count->temp;
		count->temp = 0;
		if (format[count->format] == '%')
		{
			specs = initialize_specs();
			count->format += fill_specs(format + count->format, specs, args);
			if (is_error(specs))
				count->print += print_til_percent(format);
			else
				count->print += print_arg(args, specs, print);
			free(specs);
		}
		else if (format[count->format] != '\0')
			count->format++;
	}
	return (count->print);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	t_fp_arg	*print;
	t_count		*count;
	int			total_count;

	va_start(args, format);
	print = initialize_print_functions();
	count = initialize_count();
	total_count = ft_vprintf(format, args, print, count);
	free(count);
	free(print);
	va_end(args);
	return (total_count);
}

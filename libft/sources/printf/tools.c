/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:10:59 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 00:00:32 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define NULL_LEN 6

int				ft_antoi(const char *s, int length)
{
	char		*temp;
	int			i;

	temp = ft_strnew(length + 1);
	temp = ft_strncpy(temp, s, length);
	i = ft_atoi(temp);
	free(temp);
	return (i);
}

void			ft_putstrn(const char *s, int length)
{
	int			i;

	i = 0;
	while (i < length)
	{
		ft_putchar(s[i]);
		i++;
	}
}

int				print_null(t_specs *specs)
{
	if (specs->precision <= -1 || specs->precision > NULL_LEN)
		specs->arg_len = NULL_LEN;
	else
		specs->arg_len = specs->precision;
	if (!(specs->flags & MINUS))
		specs->spaces_len = print_width_string(specs);
	if (specs->precision <= -1 || specs->arg_len < specs->precision)
		ft_putstr("(null)");
	else
		ft_putstrn("(null)", specs->precision);
	return (specs->arg_len + specs->spaces_len);
}

int				is_error(t_specs *specs)
{
	return (!(is_conversion(specs->conversion)));
}

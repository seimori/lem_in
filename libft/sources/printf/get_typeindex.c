/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_typeindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:26:39 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 22:05:36 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			get_typeindex(t_specs *specs)
{
	if (specs->conversion == 'c')
		return (C);
	if (specs->conversion == 's')
		return (S);
	if (specs->conversion == 'p')
		return (P);
	if (specs->conversion == '%')
		return (PERCENT);
	if (specs->conversion == 'd' || specs->conversion == 'i'
			|| specs->conversion == 'o' || specs->conversion == 'x'
			|| specs->conversion == 'X' || specs->conversion == 'u')
		return (I);
	if (specs->conversion == 'f')
		return (F);
	return (ERROR);
}

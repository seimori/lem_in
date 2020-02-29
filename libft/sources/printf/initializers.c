/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:16:27 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 17:44:41 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_specs				*initialize_specs(void)
{
	t_specs	*specs;

	specs = (t_specs*)ft_memalloc(sizeof(t_specs));
	specs->flags = 0;
	specs->width = 0;
	specs->precision = 0;
	specs->lengthmodifier = 0;
	specs->conversion = 0;
	specs->typeindex = -1;
	specs->is_negative = 0;
	specs->is_zero = 0;
	specs->arg_len = 0;
	specs->spaces_len = 0;
	specs->special = 0;
	return (specs);
}

t_fp_arg			*initialize_print_functions(void)
{
	t_fp_arg		*print;

	print = (t_fp_arg*)ft_memalloc(sizeof(t_fp_arg) * 6);
	print[C] = &print_c;
	print[I] = &print_int;
	print[F] = &print_float;
	print[S] = &print_s;
	print[P] = &print_p;
	print[PERCENT] = &print_percent;
	return (print);
}

t_count				*initialize_count(void)
{
	t_count			*count;

	count = (t_count*)ft_memalloc(sizeof(t_count));
	count->format = 0;
	count->print = 0;
	count->temp = 0;
	return (count);
}

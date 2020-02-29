/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:55:37 by imorimot          #+#    #+#             */
/*   Updated: 2019/04/25 17:31:44 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isspace(int c)
{
	unsigned char	uc_c;

	uc_c = (unsigned char)c;
	if (uc_c == '\t' || uc_c == '\n' || uc_c == '\v'
			|| uc_c == '\f' || uc_c == '\r' || uc_c == ' ')
		return (1);
	else
		return (0);
}

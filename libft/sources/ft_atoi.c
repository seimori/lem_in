/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:21:07 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/09 17:02:20 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		ft_checksign(char c)
{
	if (c == '-')
		return (1);
	else if (c == '+')
		return (2);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int		i;
	long	toi;
	char	neg;

	i = 0;
	toi = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((neg = ft_checksign(str[i])) > 0)
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		toi = toi * 10 + (str[i] - '0');
		i++;
	}
	if (toi < 0 && neg == 1)
		toi = 0;
	else if (toi < 0)
		toi = -1;
	if (neg == 1)
		toi = -toi;
	return (toi);
}

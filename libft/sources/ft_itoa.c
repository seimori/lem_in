/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:44:18 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/09 17:04:15 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_ilen(int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		neg;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	neg = -1;
	if (n < 0)
		neg = 1;
	if (!(str = ft_strnew(ft_ilen(n) + (neg + 1) / 2)))
		return (NULL);
	while (n != 0)
	{
		str[ft_ilen(n) + (neg + 1) / 2 - 1] = (n % 10) * -neg + '0';
		n /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

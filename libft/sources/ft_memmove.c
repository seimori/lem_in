/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:48:53 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/09 17:08:52 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*c_src;
	char	*c_dst;

	i = 1;
	c_src = (char*)src;
	c_dst = (char*)dst;
	if (c_src < c_dst)
	{
		while (i <= len)
		{
			c_dst[len - i] = c_src[len - i];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

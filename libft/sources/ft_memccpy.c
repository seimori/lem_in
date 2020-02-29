/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:39:09 by imorimot          #+#    #+#             */
/*   Updated: 2020/02/04 18:33:31 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*c_src;
	char			*c_dst;
	unsigned char	uc_c;

	i = 0;
	c_src = (char*)src;
	c_dst = (char*)dst;
	uc_c = (unsigned char)c;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		if ((unsigned char)c_src[i] == uc_c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}

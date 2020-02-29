/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:07:54 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/09 17:14:15 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *s)
{
	char	*rev;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(rev = ft_strnew(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != 0)
	{
		rev[ft_strlen(s) - i - 1] = s[i];
		i++;
	}
	return (rev);
}

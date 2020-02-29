/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:26:28 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/09 17:11:47 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(*src) * (ft_strlen(src) + 1))))
		return (NULL);
	ft_strcpy(str, src);
	return (str);
}

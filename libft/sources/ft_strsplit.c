/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:24:26 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/09 17:14:21 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static size_t	ft_strsize(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_tabsize(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(s) * (ft_tabsize(s, c) + 1))))
		return (NULL);
	while (i < ft_tabsize(s, c))
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		if (s[j] != '\0')
			if (!(tab[i] = ft_strsub(s, j, ft_strsize(&s[j], c))))
				return (NULL);
		j += ft_strsize(&s[j], c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

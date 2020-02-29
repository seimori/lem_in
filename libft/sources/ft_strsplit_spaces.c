/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:24:26 by imorimot          #+#    #+#             */
/*   Updated: 2020/02/06 17:28:14 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static size_t	ft_strsize(char const *s)
{
	size_t	i;

	i = 0;
	while (!ft_isspace(s[i]) && s[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_tabsize(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (ft_isspace(s[i]) && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			j++;
		while (!ft_isspace(s[i]) && s[i] != '\0')
			i++;
	}
	return (j);
}

char			**ft_strsplit_spaces(char const *s)
{
	size_t	i;
	size_t	j;
	char	**tab;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(s) * (ft_tabsize(s) + 1))))
		return (NULL);
	while (i < ft_tabsize(s))
	{
		while (ft_isspace(s[j]) && s[j] != '\0')
			j++;
		if (s[j] != '\0')
			if (!(tab[i] = ft_strsub(s, j, ft_strsize(&s[j]))))
				return (NULL);
		j += ft_strsize(&s[j]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

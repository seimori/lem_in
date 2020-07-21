/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:48:23 by ariperez          #+#    #+#             */
/*   Updated: 2020/03/15 17:07:18 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*ft_strjoinfree(char *s1, char *s2, char bonus, int tofree)
{
	size_t	size;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + (bonus ? 1 : 0);
	if ((join = (char *)malloc(sizeof(*join) * (size + 1))) == NULL)
		return (NULL);
	join = ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	if (bonus)
		join[size - 1] = bonus;
	join[size] = '\0';
	if (tofree == 1 || tofree == 3)
		free(s1);
	if (tofree == 2 || tofree == 3)
		free(s2);
	return (join);
}

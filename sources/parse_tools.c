/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2020/03/21 16:07:26 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*li_lstnew()
{
	t_room	*new;

	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	new->id = -1;
	new->x = 0;
	new->y = 0;
	new->name = NULL;
	new->score = INF;
	new->next = NULL;
	new->trail = NULL;
	new->route = NULL;
	new->ants = 0;
	return (new);
}

char	*get_name(char *str)
{
	int		i;
	char	*dst;
    char    tmp;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != ' ')
		i++;
	if (str[i] == '\n')
        return ((dst = ft_strdup(str)) ? dst : NULL);
    tmp = str[i];
    str[i] = '\0';
	if (!(dst = ft_strdup(str)))
        return (NULL);
    str[i] = tmp;
    return (dst);
}

char	*ft_strstopchr(char *s, int c, int stop)
{
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0' && s[i] != stop)
		i++;
	if (s[i] == c || c == '\0')
		return (s + i);
	else
		return (NULL);
}

char		*li_atoi(char *str, int *target, int stop)
{
	int		i;
	int		neg;
	int		nbr;
	long	farfromint;

	if (!str)
		return (NULL);
	i = 0;
	farfromint = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
		neg = (str[i++] == '-') ? -1 : 1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		farfromint = farfromint * 10;
		farfromint += (str[i] - '0');
		i++;
	}
	nbr = neg * farfromint;
	if (i == 0 || (str[i] != stop && (str[i] < '0' || '9' < str[i])) ||
	nbr != neg * farfromint || i > 12)
		return (NULL);
	*target = nbr;
	return (str + i);
}

int		clean_room_list(t_in *e, t_room *mem)
{
	t_room	*tmp;
	t_room	*to_free;

	if ((e->room_count = mem->id + 1) == -1 || !e->end_room ||
		e->end_room->id == -1)
		return (0);
	mem = e->room;
	while (mem)
	{
		if (mem->next && mem->next->score == 0)
		{
			if (mem->next->id == -1)
				return (0);
			tmp = mem->next;
			mem->next = mem->next->next;
			tmp->next = e->room->next;
			to_free = e->room;
			e->room = tmp;
		}
		mem = mem->next;
	}
	free(to_free);
	return (e->room->score == 0 ? 1 : 0);
}

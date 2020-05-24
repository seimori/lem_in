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

t_memlist	*li_lstnew()
{
	t_memlist	*new;

	if (!(new = malloc(sizeof(t_memlist))))
		return (NULL);
	if (!(new->names = malloc(sizeof(t_names))))
		return (NULL);
	new->names->id = -1;
	new->names->startend = 0;
	new->n = NULL;
	return (new);
}

char	*ft_strcut(char *str, int c, int part)
{
	int		i;
	char	*dst;
    char    tmp;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != c)
		i++;
	if (str[i] == '\n' && part == 0)
		return ((dst = ft_strdup(str)) ? dst : NULL);
	if (str[i] == '\n' && part == 1)
		return (NULL);
	tmp = str[i];
    str[i] = '\0';
	if (part == 1)
		return ((dst = ft_strdup(str + i + 1)) ? dst : NULL);
    if (!(dst = ft_strdup(str)))
        return (NULL);
    str[i] = tmp;
	return (dst);
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

int		list_to_tab(t_env *e, t_memlist *mem, int room)
{
	int			i;
	t_memlist	*f;
	int			start;
	int			end;

	e->nb_room = room;
	if (!(e->names = malloc(sizeof(t_names*) * e->nb_room + 1)))
		return (0);
	i = 0;
	start = 0;
	end = 0;
	while (mem->n)
	{
		f = mem;
		mem = mem->n;
		free(f);
		if (mem->names->startend == 1 && mem->names->id != -1)
			start = 1;
		if (mem->names->startend == 2 && mem->names->id != -1)
			end = 1;
        
		e->names[i++] = mem->names;
	}
	free(mem);
	return (start == 1 && end == 1 ? 1 : 0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:43:54 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/09 17:05:25 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;
	t_list	*swap;

	if (lst)
	{
		swap = f(lst);
		if (!(nlst = ft_lstnew(swap->content, swap->content_size)))
			return (NULL);
		nlst->next = ft_lstmap(lst->next, f);
		return (nlst);
	}
	else
		return (NULL);
}

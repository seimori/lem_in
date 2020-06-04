/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:12:17 by seimori           #+#    #+#             */
/*   Updated: 2020/02/04 18:34:46 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

#define TRUE 1
#define FALSE 0

int			ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (TRUE);
	else
		return (FALSE);
}

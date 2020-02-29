/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:01:01 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/09 17:09:56 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	ui_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ui_n = -n;
	}
	else
		ui_n = n;
	if (ui_n >= 10)
	{
		ft_putnbr_fd((ui_n) / 10, fd);
		ft_putchar_fd((ui_n) % 10 + '0', fd);
	}
	else
		ft_putchar_fd((ui_n) % 10 + '0', fd);
}

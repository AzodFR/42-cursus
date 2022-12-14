/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:56:23 by azod              #+#    #+#             */
/*   Updated: 2020/12/03 19:48:20 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	unsigned int base;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		base = -n;
	}
	else
		base = n;
	if (base >= 10)
		ft_putnbr_fd(base / 10, fd);
	n = base % 10 + '0';
	ft_putchar_fd(n, fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:09:24 by azod              #+#    #+#             */
/*   Updated: 2021/02/11 12:26:34 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nbtr)
{
	long int nb;
	int neg;
	int i;

	i = 0;
	neg = 0;
	nb = 0;
	while (nbtr[i] && ((nbtr[i] >= 9 && nbtr[i] <= 13) || nbtr[i] == ' '))
		i++;
	if (nbtr[i] == '+' || nbtr[i] == '-')
	{
		if (nbtr[i] == '-')
			neg++;
		i++;
	}
	while (nbtr[i] && (nbtr[i] >= '0' && nbtr[i] <= '9'))
	{
		nb *= 10;
		nb += nbtr[i++] - 48;
	}
	if (i > 20)
		return (neg ? 0 : -1);
	return (neg ? -nb : nb);
}

long long ft_atoll(const char *nbtr)
{
	long long nb;
	int neg;
	int i;

	i = 0;
	neg = 0;
	nb = 0;
	while (nbtr[i] && ((nbtr[i] >= 9 && nbtr[i] <= 13) || nbtr[i] == ' '))
		i++;
	if (nbtr[i] == '+' || nbtr[i] == '-')
	{
		if (nbtr[i] == '-')
			neg++;
		i++;
	}
	while (nbtr[i] && (nbtr[i] >= '0' && nbtr[i] <= '9'))
	{
		nb *= 10;
		nb += nbtr[i++] - 48;
	}
	if (i > 20)
		return (neg ? 0 : -1);
	return (neg ? -nb : nb);
}

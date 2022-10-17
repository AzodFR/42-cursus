/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_direct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:41:59 by azod              #+#    #+#             */
/*   Updated: 2020/12/05 00:14:04 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_direct(const char *format)
{
	int ret;

	ret = ft_strlen(format);
	write(1, format, ret);
	return (ret);
}

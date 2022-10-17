/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:51:34 by azod              #+#    #+#             */
/*   Updated: 2021/02/17 10:42:56 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int ret;
	va_list ap;

	ret = 0;
	va_start(ap, format);
	if (!read_format(format, ap))
		return (print_direct(format));
	ret = prepare_string(format, ap);
	va_end(ap);
	return (ret);
}

int ft_dprintf(int fd, const char *format, ...)
{
	int ret;
	int back;
	va_list ap;

	ret = 0;
	back = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	va_start(ap, format);
	if (!read_format(format, ap))
		ret = print_direct(format);
	else
		ret = prepare_string(format, ap);
	va_end(ap);
	dup2(back, STDOUT_FILENO);
	close(back);
	return (ret);
}

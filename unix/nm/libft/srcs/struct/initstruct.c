/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:30:10 by azod              #+#    #+#             */
/*   Updated: 2020/12/05 00:11:45 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags initstruct(void)
{
	t_flags elem;

	elem.minus = 0;
	elem.zero = 0;
	elem.dot = -1;
	elem.star = 0;
	elem.len = 0;
	elem.type = 0;
	return (elem);
}

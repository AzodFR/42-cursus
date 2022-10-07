/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:05:39 by azod              #+#    #+#             */
/*   Updated: 2021/02/16 16:44:40 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mishell.h"

void get_env(t_env *envp)
{
	t_env *tmp;

	tmp = envp;
	while (tmp)
	{
		if (tmp->state)
			ft_envprint_one(tmp);
		tmp = tmp->next;
	}
	get_all_st(NULL)->state = 0;
}

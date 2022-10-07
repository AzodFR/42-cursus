/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_edit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:52:33 by azod              #+#    #+#             */
/*   Updated: 2021/02/03 12:48:09 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mishell.h"

t_env *env_find(t_env *env, char *name)
{
	t_env *tmp;
	int namelen;
	int envlen;

	tmp = env;
	namelen = ft_strlen(name);
	while (tmp)
	{
		envlen = ft_strlen(tmp->name);
		if (envlen >= namelen && !ft_strncmp(tmp->name, name, namelen + 1))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void env_edit_value(t_env *env, char *value)
{
	wrfree(env->value);
	env->value = ft_strdup(value);
}

void env_edit_state(t_env *env, int value)
{
	env->state = value;
}

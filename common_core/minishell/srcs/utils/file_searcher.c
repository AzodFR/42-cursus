/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_searcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:21:45 by azod              #+#    #+#             */
/*   Updated: 2021/02/18 14:16:09 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mishell.h"

char *search_cmd_local(char **args)
{
	struct stat buff;
	char test[10000];
	char *tmp;
	char *tmp2;

	tmp = ft_strjoin(getcwd(test, 10000), "/");
	tmp2 = ft_strjoin(tmp, args[0]);
	if (!stat(tmp2, &buff))
		return (tmp2);
	wrfree(tmp2);
	return (NULL);
}

char *search_cmd_abs(char **args)
{
	struct stat buff;

	if (!stat(args[0], &buff))
		return (args[0]);
	return (NULL);
}

void search_cmd(t_env *env, char **args, int i)
{
	if (args && args[0] && is_directory(args[0]))
	{
		if (!ft_strncmp(args[0], "..", 3))
			get_all_st(NULL)->state = 127;
		else
			not_exec(1, args[0]);
		return;
	}
	if (!se_path(env, i, args, 1))
		if (!se_local(env, args, 1))
			if (!se_abs(env, args, 1))
				if (get_all_st(NULL)->state != 126)
					get_all_st(NULL)->state = 127;
	return;
}

int check_cmd(t_env *env, char **args, int i)
{
	if (is_directory(args[0]))
	{
		if (!ft_strncmp(args[0], "..", 3))
			get_all_st(NULL)->state = 127;
		else
			return (not_exec(1, args[0]));
		return (0);
	}
	if (!se_path(env, i, args, 0))
		if (!se_local(env, args, 0))
			if (!se_abs(env, args, 0))
			{
				if (get_all_st(NULL)->state != 126)
					get_all_st(NULL)->state = 127;
				return (0);
			}
	return (1);
}

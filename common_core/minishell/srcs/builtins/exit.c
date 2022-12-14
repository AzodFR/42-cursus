/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:15:05 by azod              #+#    #+#             */
/*   Updated: 2021/02/18 14:12:08 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mishell.h"

static int cmd_exit_util(char **args, long long i)
{
	if (i > 2)
	{
		if (isalldigit(args[1]))
		{
			get_all_st(NULL)->exit = -1;
			get_all_st(NULL)->state = 1;
			ft_dprintf(2, "\033[32mMiShell \033[31m✘ \033[0m");
			ft_dprintf(2, "exit: too many arguments\n");
			return (-1);
		}
	}
	return (0);
}

void cmd_exit(char **args)
{
	long long i;

	i = -1;
	while (args[++i])
		;
	if (cmd_exit_util(args, i) == -1)
		return;
	get_all_st(NULL)->exit = 1;
	if (!args[1])
		return;
	i = ft_atoll(args[1]);
	if (!isalldigit(args[1]))
		get_all_st(NULL)->state = 255;
	else if (i > 255)
	{
		get_all_st(NULL)->state = i % 256;
	}
	else if (i < -255 && i % 256 == 0)
		get_all_st(NULL)->state = 255;
	else
		get_all_st(NULL)->state = i;
	return;
}

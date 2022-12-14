/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:40:46 by azod              #+#    #+#             */
/*   Updated: 2021/02/18 12:37:35 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mishell.h"

char *find_path(char *s, t_env *env)
{
	char **path;
	char *tmp;
	char *tmp2;
	struct stat buff;
	int i;

	i = -1;
	if (!env_find(env, "PATH"))
		return (NULL);
	path = ft_split(env_find(env, "PATH")->value, ':');
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		tmp2 = ft_strjoin(tmp, s);
		wrfree(tmp);
		if (!stat(tmp2, &buff))
			return (tmp2);
		wrfree(tmp2);
	}
	return (s);
}

static void underscore(t_env *env, char **args)
{
	int i;

	i = -1;
	while (args[++i])
		;
	--i;
	if (!find_path(args[i], env))
		env_edit_value(env_find(env, "_"), args[i]);
	else
		env_edit_value(env_find(env, "_"), find_path(args[i], env));
}

int end_ling(int ret, char *s)
{
	if (ret == 32257 || ret == 127)
	{
		get_all_st(NULL)->state = 127;
		ft_dprintf(2, "\033[32mMiShell \033[31m✘ \033[0m");
		ft_dprintf(2, "%s: command not found\n", s);
	}
	if (ret == 256)
		get_all_st(NULL)->state = 1;
	return (ret);
}

void dot(char **args)
{
	if (!args[1])
	{
		ft_dprintf(2, "\033[32mMiShell \033[31m✘ \033[0m");
		ft_dprintf(2, ".: not enough arguments\n");
		get_all_st(NULL)->state = 2;
	}
	else
	{
		ft_dprintf(2, "\033[32mMiShell \033[31m✘ \033[0m");
		ft_dprintf(2, ".: no such file or directory: %s\n", args[1]);
		get_all_st(NULL)->state = 1;
	}
}

int handler(char **args, t_env *env)
{
	if (!args[0])
		return (1);
	underscore(env, args);
	if (!ft_strncmp(ft_tolowers(args[0]), "pwd", 4))
		get_pwd();
	else if (!ft_strncmp(ft_tolowers(args[0]), "env", 4))
		get_env(env);
	else if (!ft_strncmp(ft_tolowers(args[0]), "cd", 3))
		change_dir(env, args);
	else if (!ft_strncmp(ft_tolowers(args[0]), "export", 7))
		export_env(env, args);
	else if (!ft_strncmp(ft_tolowers(args[0]), "unset", 6))
		unset(env, args);
	else if (!ft_strncmp(ft_tolowers(args[0]), "echo", 5))
		do_echo(args);
	else if (!ft_strncmp(ft_tolowers(args[0]), "donut", 6))
		get_all_st(NULL)->state = main_donut(args);
	else if (!ft_strncmp(ft_tolowers(args[0]), "exit", 6))
		cmd_exit(args);
	else if ((!ft_strncmp(ft_tolowers(args[0]), ".", 2)))
		dot(args);
	else
		search_cmd(env, args, -1);
	return (end_ling(get_all_st(NULL)->state, args[0]));
}

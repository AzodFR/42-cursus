/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:52:26 by azod              #+#    #+#             */
/*   Updated: 2021/02/17 16:06:59 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mishell.h"

static char *home(t_env *env, char *s)
{
	char *tmp;
	char *home_p;
	int i;
	int j;

	i = 0;
	if (!(home_p = ft_strdup(env_find(env, "HOME")->value)))
		ft_exit(MALLOC);
	if (!(tmp = wrmalloc(ft_strlen(s) + ft_strlen(home_p) + 1 * sizeof(char))))
		ft_exit(MALLOC);
	j = -1;
	while (home_p[++j])
		tmp[j] = home_p[j];
	j--;
	while (s[++i])
		tmp[i + j] = s[i];
	tmp[i + j] = 0;
	wrfree(home_p);
	wrfree(s);
	return (tmp);
}

static int check_slash(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] != '/' && i > 1)
			return (0);
	return (i > 2 ? i : 0);
}

static char *suprslash(char *s)
{
	int i;
	int j;
	char *newstring;

	i = -1;
	j = 0;
	if (check_slash(s))
		return (ft_strdup("/"));
	if (!(newstring = wrmalloc(ft_strlen(s) + 1 * sizeof(char))))
		ft_exit(MALLOC);
	while (s[++i])
	{
		if (i > 1 && s[i - 1] && s[i - 1] == '/' && s[i] == '/')
			j++;
		else
			newstring[i - j] = s[i];
	}
	newstring[i - j] = 0;
	wrfree(s);
	return (newstring);
}

static void change_dir_utils(t_env *env, char *path)
{
	char *test;

	if (env_find(env, "OLDPWD"))
		env_edit_value(env_find(env, "OLDPWD"), env_find(env, "PWD") ? env_find(env, "PWD")->value : getcwd(NULL, 0));
	else
		ft_envadd_back(&env, ft_envnew("OLDPWD", ft_strdup(env_find(env, "PWD")
															   ? env_find(env, "PWD")->value
															   : getcwd(NULL, 0))));
	if (getcwd(NULL, 10000))
		test = getcwd(NULL, 10000);
	else
		test = ft_strjoin(ft_strdup(env_find(env, "OLDPWD")->value), "/.");
	if (!ft_strncmp(path, "//", 2))
		env_edit_value(env_find(env, "PWD"), path);
	else if (!ft_strncmp(path, "/etc", 4) || !ft_strncmp(path, "/var", 4))
		env_edit_value(env_find(env, "PWD"), path);
	else if (!ft_strncmp(path, "/private", 8))
		env_edit_value(env_find(env, "PWD"), path);
	else if (env_find(env, "PWD"))
		env_edit_value(env_find(env, "PWD"), test);
	else
		ft_envadd_back(&env, ft_envnew("PWD", test));
	wrfree(path);
	get_all_st(NULL)->state = 0;
}

void change_dir(t_env *env, char **args)
{
	char *path;

	if (!args[1])
		path = ft_strdup(env_find(env, "HOME")->value);
	else
		path = ft_strdup(ft_strlen(args[1]) ? args[1] : ".");
	if (args[1] && args[1][0] == '~')
		path = home(env, path);
	if (!(path = suprslash(path)))
		ft_exit(MALLOC);
	if (chdir(path) < 0)
	{
		ft_dprintf(2, "\033[32mMiShell \033[31m??? \033[0m");
		ft_dprintf(2, "cd: %s: %s\n", path, strerror(errno));
		wrfree(path);
		get_all_st(NULL)->state = 1;
		return;
	}
	change_dir_utils(env, path);
}

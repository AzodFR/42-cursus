/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:03:32 by azod              #+#    #+#             */
/*   Updated: 2021/02/19 10:59:18 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mishell.h"

static char *free_ret_char(char *tmp, char *ret, char *string)
{
	wrfree(tmp);
	wrfree(ret);
	return (string);
}

char *switch_tmp(char *tmp, char *string, int j, int *i)
{
	wrfree(string);
	*i += j;
	return (tmp);
}

char *translate(char *s, int *i, t_all *all, char *string)
{
	int j;
	char *tmp;
	char *ret;

	j = 1;
	ret = ft_strdup(string);
	if (!ft_isdigit(s[*i + j]) && s[*i + j] != ' ')
	{
		while (s[*i + j] && (ft_isalnum(s[*i + j]) ||
							 (j == 1 && (s[*i + j] == '?' || s[*i + j] == '$')) || s[*i + j] == '_'))
			if ((j++ == 1 && (s[*i + j - 1] == '?' || s[*i + j - 1] == '$')))
				break;
	}
	else
		++j;
	tmp = switch_tmp(ft_strndup(&s[*i + 1], j - 1), string, j, i);
	if (!ft_strncmp(tmp, "?", 1))
		string = ft_strjoin(ret, ft_itoa(all->state));
	else if (!ft_strncmp(tmp, "$", 1))
		string = ft_strjoin(ret, ft_itoa(all->pid));
	else if (env_find(get_env_st(NULL), tmp))
		string = ft_strjoin(ret, env_find(get_env_st(NULL), tmp)->value);
	else
		string = ft_strjoin(ret, "");
	return (free_ret_char(tmp, ret, string));
}

char *add_one(char *s, char c)
{
	char new[2];
	char *tmp;

	new[0] = c;
	new[1] = 0;
	tmp = ft_strjoin(s, new);
	wrfree(s);
	return (tmp);
}

char *check_translation(char *s, int type, t_type *next)
{
	int i;
	char *r;
	int esc;

	i = -1;
	r = ft_strdup("");
	while (s[++i])
	{
		esc = 0;
		if ((!type && s[i] == '$' && !s[i + 1] && next) || (s[i] == '\\' && (!type || (type && s[i + 1] && (s[i + 1] == '$' || s[i + 1] == '`' || s[i + 1] == '"'))) && (esc = 1)))
			++i;
		if (!s[i])
			break;
		while (s[i] == '$' && !esc && s[i + 1] && s[i + 1] != ' ' && (s[i + 1] == '?' || s[i + 1] == '\'' || s[i + 1] == '\"' || s[i + 1] == '_' || s[i + 1] == '@' || s[i + 1] == '*' || ft_isalnum(s[i + 1])))
			r = translate(s, &i, get_all_st(NULL), r);
		if (!s[i])
			break;
		r = add_one(r, s[i]);
	}
	return (r);
}

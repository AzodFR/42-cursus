/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:25:27 by azod              #+#    #+#             */
/*   Updated: 2021/02/18 14:15:58 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mishell.h"

char *get_tild(void)
{
	int state;

	state = get_all_st(NULL)->state;
	if (state == 0 || state == 130 || state == 131)
		return ("\033[36m~ \033[0m");
	else
		return ("\033[31m~ \033[0m");
}

char *get_msg(int code)
{
	if (code == EXIT_SUCCESS)
		return ("SUCCESS");
	if (code == EXIT_FAILED)
		return ("EXIT FAILED");
	if (code == MALLOC)
		return ("MALLOC ERROR");
	if (code == QUIT)
		return ("SUCCESS");
	if (code == BAD_ENV)
		return ("CORRUPTED ENV");
	return (NULL);
}

void ft_exit(int code)
{
	ft_dprintf(2, "exit\n");
	if (code != 0 && code != 4)
		ft_dprintf(2, "Status: %s\n", get_msg(code));
	wrdestroy();
	exit(get_all_st(NULL)->state);
}

char *ft_strfdup(char *s, char *bef)
{
	wrfree(bef);
	return (ft_strdup(s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 00:05:23 by azod              #+#    #+#             */
/*   Updated: 2021/02/11 15:51:28 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mishell.h"

void exec_cmd(t_tree *root)
{
	int type;

	if (get_all_st(NULL)->exit == 1)
		return;
	if (!root)
		return;
	type = root->cmd->type;
	if (type == 2)
		exec_pipe(root, 1, 0);
	else if (type > 2 && type < 6)
		exec_redir(root);
	else
		handler(prep_cmd(root->cmd, 0), get_env_st(NULL));
}

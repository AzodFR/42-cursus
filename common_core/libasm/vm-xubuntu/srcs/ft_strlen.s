# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azod     <contact@azod.io>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 00:11:18 by azod              #+#    #+#              #
#    Updated: 2020/12/28 00:18:36 by azod             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

section .text
global ft_strlen

ft_strlen:
	push	rbp
	xor		rax, rax
	jmp		_loop

_loop:
	cmp byte	[rdi], 0
	jne			_inc_loop
	pop			rbp
	ret

_inc_loop:
	inc		rax
	inc		rdi
	jmp		_loop

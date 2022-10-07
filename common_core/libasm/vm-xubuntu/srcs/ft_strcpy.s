# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   ft_strcpy.s                                        :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: azod     <contact@azod.io>                 +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/12/28 10:26:06 by azod              #+#    #+#             #
#   Updated: 2020/12/28 10:26:14 by azod             ###   ########lyon.fr   #
#                                                                            #
# ************************************************************************** #



section .text
global ft_strcpy

ft_strcpy:
	push	rbp
	push	r8
	push	r9
	xor		r8, r8
	jmp		_loop

_loop:
	cmp byte	[rdi + r8], 0
	je			_cpy
	jmp			_end

_cpy:
	cmp byte	[rsi], 0
	je			_end
	mov			r9b, [rsi]
	mov byte	[rdi + r8], r9b
	inc			rsi
	inc			r8
	jmp			_loop

_end:
	mov byte	[rdi + r8], 0
	mov			rax, rdi
	pop			r8
	pop			r9
	pop			rbp
	ret

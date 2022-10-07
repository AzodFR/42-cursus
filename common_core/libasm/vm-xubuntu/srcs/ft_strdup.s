# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   ft_strdup.s                                        :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: azod     <contact@azod.io>                 +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/12/28 12:13:35 by azod              #+#    #+#             #
#   Updated: 2020/12/28 12:13:35 by azod             ###   ########lyon.fr   #
#                                                                            #
# ************************************************************************** #
# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   ft_strdup.s                                        :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: azod     <contact@azod.io>                 +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/12/28 12:13:35 by azod              #+#    #+#             #
#   Updated: 2020/12/28 12:13:35 by azod             ###   ########lyon.fr   #
#                                                                            #
# ************************************************************************** #

section .text
global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	push	rdi
	call	ft_strlen
	mov		rdi, rax
	call	malloc
	or		rax, rax
	je		_error
	pop		rsi
	mov		rdi, rax
	call	ft_strcpy
	ret

_error:
	pop rdi
	ret

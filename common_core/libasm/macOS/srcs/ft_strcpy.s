section .text
global _ft_strcpy


_ft_strcpy:
	push	rbp
	push	r8
	push	r9
	xor		r8, r8
	jmp		_loop

_loop:
	cmp byte	[rsi], 0
	jne			_cpy
	jmp			_end

_cpy:
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

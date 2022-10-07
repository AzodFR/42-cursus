section .text
global _ft_strlen

_ft_strlen:
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

section	.text
global	_ft_strcmp

_ft_strcmp:
	push	rbp
	push	r8
	push	r9
	push	r10
	push	r11
	xor		r8, r8
	xor		r9, r9
	xor		r10, r10
	xor		r11, r11
	jmp		_loop

_loop:
	mov		r10b, byte [rdi + r8]
	mov		r11b, byte [rsi + r9]
	cmp		r10b, r11b
	je		_check
	jmp		_return

_check:
	or		r10b, r10b
	je		_return
	or		r11b, r11b
	je		_return
	jmp		_inc_loop

_return:
	sub		r10, r11
	mov		rax, r10
	pop		r8
	pop		r9
	pop		r10
	pop		r11
	pop		rbp
	ret

_inc_loop:
	inc		r8
	inc		r9
	jmp		_loop

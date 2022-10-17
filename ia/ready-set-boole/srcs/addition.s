section .text
global bit_add


bit_add:
	push rbx
    mov rax, rdi
    pop rbx
	ret

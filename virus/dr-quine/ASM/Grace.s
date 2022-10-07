%define _not_main main
global _not_main
extern open
extern dprintf
section .text
;this is not a main
_not_main:
	push rbx
	mov rdi, filename
	mov rsi, 577
	mov rdx, 644
	call open WRT ..plt
	mov rdi, rax
	mov rsi, msg
	mov rdx, msg
	mov rcx, 10
	mov r8, 34
	mov r9, 9
	call dprintf WRT ..plt
	pop rbx
	ret

section .data
	filename db "Grace_kid.s", 0
	msg db "%%define _not_main main%2$cglobal _not_main%2$cextern open%2$cextern dprintf%2$csection .text%2$c;this is not a main%2$c_not_main:%2$c%4$cpush rbx%2$c%4$cmov rdi, filename%2$c%4$cmov rsi, 577%2$c%4$cmov rdx, 644%2$c%4$ccall open WRT ..plt%2$c%4$cmov rdi, rax%2$c%4$cmov rsi, msg%2$c%4$cmov rdx, msg%2$c%4$cmov rcx, 10%2$c%4$cmov r8, 34%2$c%4$cmov r9, 9%2$c%4$ccall dprintf WRT ..plt%2$c%4$cpop rbx%2$c%4$cret%2$c%2$csection .data%2$c%4$cfilename db %3$cGrace_kid.s%3$c, 0%2$c%4$cmsg db %3$c%1$s%3$c, 0", 0
;first comment
section .text
extern printf
global main

quine:
	push rbx
	mov rdi, strF
	mov rsi, 10
	mov rdx, 9
	mov rcx, strF
	mov r8, 34
	call printf WRT ..plt
	pop rbx
	ret

main:
	push rbx
	call quine ;second comment
	ret

section .data
	strF db ";first comment%1$csection .text%1$cextern printf%1$cglobal main%1$c%1$cquine:%1$c%2$cpush rbx%1$c%2$cmov rdi, strF%1$c%2$cmov rsi, 10%1$c%2$cmov rdx, 9%1$c%2$cmov rcx, strF%1$c%2$cmov r8, 34%1$c%2$ccall printf WRT ..plt%1$c%2$cpop rbx%1$c%2$cret%1$c%1$cmain:%1$c%2$cpush rbx%1$c%2$ccall quine ;second comment%1$c%2$cret%1$c%1$csection .data%1$c%2$cstrF db %4$c%3$s%4$c, 0", 0
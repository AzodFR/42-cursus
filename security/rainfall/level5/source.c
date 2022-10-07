#include <stdio.h>
#include <stdlib.h>

void o()
{
    system("/bin/sh");
    exit(1);
}

void n()
{
    char s[512];
    fgets(s, 512, stdin);
    printf(s);
    exit(1);
}

int main()
{
    n();
    return;
}
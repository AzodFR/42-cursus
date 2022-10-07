#include <stdlib.h>
#include <stdio.h>

void p(char *s)
{
    printf(s);
    return;
}

void n()
{
    char s[512];
    int i = 0;

    fgets(s, 512, stdin);
    p(s);
    if (i == 16930116)
    {
        system("/bin/cat /home/user/level5/.pass");
    }
    return;
}

int main()
{
    n();
    return;
}
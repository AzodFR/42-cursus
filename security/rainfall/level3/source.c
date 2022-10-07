#include <stdio.h>
#include <stdlib.h>
void v()
{
    char str[512];
    int i = 0;

    fgets(str, 512, stdin);
    printf(str);
    if (i == 64)
    {
        fwrite("Wait what?!\n", 1, 12, stdout);
        system("/bin/sh");
    }
    return;
}

int main()
{
    v();
    return;
}

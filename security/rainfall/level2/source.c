#include <stdlib.h>
#include <stdio.h>
void p()
{
    void *ebp;
    char str[76];

    fflush(stdout);
    ebp = gets(str);

    if (((unsigned int)ebp & 0xb0000000) == 0xb0000000)
    {
        printf("(%p)\n", ebp);
        exit(1);
    }
    puts(str);
    strdup(str);
    return;
}

int main()
{
    p();
    return;
}
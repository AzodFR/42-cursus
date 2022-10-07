#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void n()
{
   system("/bin/cat /home/user/level7/.pass");
   return;
}

void m(char *s)
{
    puts(s);
    return;
}

int main(int ac, char **av)
{
    char *s;

    s = malloc(64);  
    void (*f)(char *s) = malloc(4);
    f = m;
    strcpy(s, av[1]);
    f(s);
    return;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av)
{
    if (atoi(av[1]) == 423)
    {
        char *cmd = strdup("/bin/sh");

        gid_t gid = getegid();
        uid_t uid = geteuid();

        setresgid(gid, gid, gid);
        setresuid(uid, uid, uid);

        char *arg[1] = {0};

        execve(cmd, arg, 0);
    }
    else
    {
        fwrite("No !\n", 1, 5, stderr);
    }
}
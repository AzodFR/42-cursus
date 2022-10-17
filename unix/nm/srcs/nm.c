#include "nm.h"

t_apps *parseNames(char ac, char **av)
{
    t_apps *executable;
    if (!(executable = wrmalloc(sizeof(t_apps))))
        return NULL;
    char **appNames;
    if (ac < 2)
    {
        if (!(appNames = wrmalloc(2 * sizeof(char *))))
            return NULL;
        if (!(appNames[0] = ft_strdup("a.out")))
            return NULL;
        appNames[1] = NULL;
    }
    else
    {
        if (!(appNames = wrmalloc(ac * sizeof(char *))))
            return NULL;
        for (int i = 1; i < ac; i++)
        {
            if (!(appNames[i - 1] = ft_strdup(av[i])))
                return NULL;
        }
        appNames[ac - 1] = NULL;
    }
    executable->n = ac - 1;
    executable->appNames = appNames;
    return executable;
}

int8_t tryFiles(t_apps *executables)
{
    stats *files;
    int *fds;
    if (!(files = wrmalloc(executables->n * sizeof(stats))))
    {
        ft_printf("\e[31mnm\e[0m: Error during malloc()\n");
        return 0;
    }
    if (!(fds = wrmalloc(executables->n * sizeof(int))))
    {
        ft_printf("\e[31mnm\e[0m: Error during malloc()\n");
        return 0;
    }
    executables->appStats = files;
    executables->fd = fds;
    for (int i = 0; i < executables->n; i++)
    {
        fds[i] = -1;
        int fd;
        if ((fd = open(executables->appNames[i], O_RDONLY)) == -1)
        {
            ft_printf("\e[31mnm\e[0m: \e[31merror\e[0m: %s: No such file or directory.\n", executables->appNames[i]);
            return 0;
        }
        fds[i] = fd;
        if (fstat(fd, &(files[i])) == -1)
        {
            ft_printf("\e[31mnm\e[0m: \e[31merror\e[0m: %s: Can't fstat\n", executables->appNames[i]);
            return 0;
        }
    }

    return 1;
}

int main(int ac, char **av)
{
    t_apps *executables;
    executables = parseNames(ac, av);
    if (!executables->appNames)
    {
        wrdestroy();
        ft_printf("\e[31m%s\e[0m: Error during malloc()\n", av[0]);
        return 1;
    }
    if (!tryFiles(executables))
    {
        for (int i = 0; executables->fd[i] != -1; i++)
            close(executables->fd[i]);
        wrdestroy();
        return 1;
    }
    off_t pa_offset = 0 & ~(sysconf(_SC_PAGE_SIZE) - 1);
    for (int i = 0; i < executables->n; i++)
    {

        char *addr;

        addr = mmap(NULL,  executables->appStats[i].st_size, PROT_READ,
                    MAP_PRIVATE, executables->fd[i], pa_offset);
        if (addr == MAP_FAILED)
            ft_printf("Error mmap");
        else
            write(1, addr + pa_offset, executables->appStats[i].st_size);
    }
    return 0;
}
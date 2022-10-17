#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "ft_printf.h"

typedef struct stat
stats;

typedef struct s_apps
{
    int n;
    char **appNames;
    stats* appStats;
    int *fd;

} t_apps;

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>

typedef struct t_opt
{
    int t;
    int c;
} t_opt;

t_opt* get_opt(int ac, char** av);


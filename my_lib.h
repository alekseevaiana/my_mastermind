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
    int t_val; // attempts
    char* c_val;
} t_opt;

typedef struct t_secret_code
{
    // 0: str[0]
    // 1: str[1]
    // 2: str[2]
    // 3: str[3]
} t_secret_code;

t_opt* get_opt(int ac, char** av);
int is_digits(char* str);


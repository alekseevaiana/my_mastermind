#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>


#include <linux/stat.h>

#include <stdbool.h>
#include <fcntl.h>
#include <ctype.h>

typedef struct t_opt
{
    int t;
    int c;
    int t_val; // attempts
    char* c_val;
} t_opt;

typedef struct t_secret_code
{
    // 0: str[0] // with atoi
    // 1: str[1]
    // 2: str[2]
    // 3: str[3]
    // 
} t_secret_code;

typedef struct t_user_code
{
    // 0: str[0] // with atoi
    // 1: str[1]
    // 2: str[2]
    // 3: str[3]
    // well_placed int
    // misplaced int 
} t_user_code;

t_opt* get_opt(int ac, char** av);
int is_digits(char* str);
char* my_strcpy(char* dst, char* str);
char* read_input(int fd);


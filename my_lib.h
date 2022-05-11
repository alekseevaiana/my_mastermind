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
    char* c_val; // secret code
} t_opt;

typedef struct t_guess_result
{
    int well_placed_amount;
    int missplaced_amount;
} t_guess_result;

t_opt* get_opt(int ac, char** av);
int is_digits(char* str);
char* my_strcpy(char* dst, char* str);
char* read_input(int fd);
char* my_strdup(char* str);


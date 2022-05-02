#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>

int main(int ac, char** av) {
    printf("hello world %d %s\n", ac, av[1]);
    return 0;
}
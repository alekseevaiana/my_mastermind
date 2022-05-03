#include "my_lib.h"

int main(int ac, char** av) {
    t_opt* options = get_opt(ac, av);
    printf("option c [%d], option t [%d]\n", options->c, options->t);
    printf("hello world %d %s\n", ac, av[1]);
    return 0;
}
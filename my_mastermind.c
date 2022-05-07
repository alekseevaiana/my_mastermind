#include "my_lib.h"

int main(int ac, char** av) {
    t_opt* options = get_opt(ac, av);
    printf("option c [%d], option t [%d]\n", options->c, options->t);
    
    free(options);
    return 0;
}
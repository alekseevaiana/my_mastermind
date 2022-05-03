#include "my_lib.h"

void set_option(t_opt* opt, char* str)
{
    int index;
    index = 0;
    while (str[index] != '\0')
    {
        if (str[index] == 't')
        {
            opt->t = 1;
        }
        if (str[index] == 'c')
        {
            opt->c = 1;
        }
        index += 1;
    }
}

int is_option(char* str)
{
    if (str[0] == '-')
    {
        return 1;
    }
    return 0;
}

t_opt* init_opt()
{
    t_opt* opt = (t_opt*)malloc(sizeof(t_opt));
    opt->t = 0;
    opt->c = 0;
    return opt;
}
t_opt* get_opt(int ac, char** av)
{
    t_opt* opt = init_opt();
    int index;
    index = 0;
    while (index < ac)
    {
        if (is_option(av[index]) == 1)
        {
            set_option(opt, av[index] + 1);
        }
        index += 1;
    }
    return opt;
}
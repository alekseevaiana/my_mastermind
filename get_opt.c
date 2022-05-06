#include "my_lib.h"


// read only str with "-" like -t or -c or -ct
void set_option(t_opt* opt, char* str, char* opt_str)
{
    int index;
    index = 0;
    while (str[index] != '\0')
    {
        if (str[index] == 't')
        {
            opt->t = 1;
            opt->t_val = atoi(opt_str);
        }
        if (str[index] == 'c')
        {
            opt->c = 1;
            opt->c_val = opt_str;
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

int check_option_value(char* str)
{
    if (is_digits(str) == 1)
    {
        printf("WRONG INPUT MUST CONTAIN ONLY DIGITS\n");
    };
    return 0;
}

t_opt* init_opt()
{
    t_opt* opt = (t_opt*)malloc(sizeof(t_opt));
    opt->t = 0;
    opt->c = 0;
    opt->t_val = 10; 
    opt->c_val = ""; // generate random code
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
            check_option_value(av[index + 1]); // if option value contains only digits!
            // also check if there is an option value aftre option         
            set_option(opt, av[index] + 1, av[index + 1]); // av[index] + 1 -> is a pointer that points to next char in a str
        }
        index += 1;
    }
    printf("options: t attempts is: %d,\noption: c is: %s\n", opt->t_val, opt->c_val);
    return opt;
}
#include "my_lib.h"

char* copy_to_rest(char buf, char* prev_rest, int rest_index)
{
    char* rest;
    rest = malloc(sizeof(char) * (1 + rest_index) + 1);

    if (prev_rest != NULL)
    {
        my_strcpy(rest, prev_rest);
    }
    int buf_index;

    buf_index = 0;
    while (buf_index < 1)
    {
        rest[rest_index] = buf;
        rest_index++;
        buf_index++;
    }
    rest[rest_index] = '\0';
    return rest;
}

char* read_input(int fd)
{
    char buff;
    char* input;
   
    int read_size = 0;

    write(0, "[", 1);
    write(0, "]> ", 3);

    while (read(fd, &buff, 1) > 0 && buff != '\n')
    {
        input = copy_to_rest(buff, input, read_size);
        read_size += 1;
    }
    return input;
}
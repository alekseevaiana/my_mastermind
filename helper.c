#include "my_lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int u_decimal_to_str(unsigned int nb)
{
    int i;

    i = 0;
    if (nb >= 10)
    {
        i = i + u_decimal_to_str(nb / 10);
        i = i + u_decimal_to_str(nb % 10);
    }
    else
    {
        my_putchar(nb + '0');
        i++;
    }
    return i;
}

int decimal_to_str(int nb)
{
    int i;

    i = 0;
    if (nb < 0)
    {
        nb = nb * -1;
        my_putchar('-');
        i++;
    }
    i = i + u_decimal_to_str(nb);
    return i;
}

char* my_strcpy(char* dst, char* str)
{
    int index;
    index = 0;
    while (str[index] != '\0')
    {
        dst[index] = str[index];
        index++;
    }
    dst[index] = '\0';
    return dst;
}

// copy without malloc
int my_strcmp(char* a, char* b)
{
    int count;

    count = 0;
    while (a[count] != '\0' && b[count] != '\0' && a[count] == b[count])
        count++;
    return (a[count] - b[count]);
}

int my_strlen(char* str)
{
    int index;
    index = 0;
    while (str[index] != '\0')
    {
        index += 1;
    }
    return index;
}

// copy with malloc
char* my_strdup(char* str)
{
    int index;
    int length;
    char* my_str;

    length = my_strlen(str);
    my_str = (char*)malloc(sizeof(char) * length + 1);
    if (!my_str)
    {
        return 0;
    }
    index = 0;
    while (str[index] != '\0')
    {
        my_str[index] = str[index];
        index += 1;
    }
    my_str[index] = '\0';
    return my_str;
}

int is_digits(char* str)
{
    int index = 0;
    while (str[index] != '\0') {
        if(str[index] < '0' || str[index] > '9')
        {
            return 1;
        }
        index++;
    }
    return 0;
}
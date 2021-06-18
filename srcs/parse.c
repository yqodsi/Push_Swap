#include "push_swap.h"

int get_value(char *str, int *nb)
{
    int res;
    int b;

    b = 1;
    res = 0;

    if (*str == '-')
        b = -1;
    if (*str == '-' || *str == '+')
        ++str;
    while (*str && *str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str++ - '0');
    }
    if (*str != '\0')
        return (1);
    *nb = ((int)res * b);
    return (0);
}

int is_duplicate(t_stack *stack, int nb)
{
    int i;

    i = 0;
    while (i <= stack->top)
    {
        if (nb == stack->arr[i].value)
            return (TRUE);
        i++;
    }
    return (FALSE);
}
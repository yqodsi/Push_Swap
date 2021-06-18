#include "push_swap.h"

void    print_stack(t_stack *a, t_stack *b)
{
    int len = a->top;
    if (a->top < b->top)
        len = b->top;
    printf("%-15s\t|%-15s|\n", "    stack a", "    stack b");
    printf("=================================\n");

    for(;len >= 0; len--)
    {
        if (len > a->top)
            printf("       %-7s\t|", "");
        else
            printf("       %-7d\t|", a->arr[len].value);
        if (len > b->top)
            printf("       %-7s|\n", "");
        else
            printf("       %-7d|\n", b->arr[len].value);
    }
    printf("=================================\n");
}

int main(int ac, char **av)
{

    int nb;

    t_data data;
    t_stack a;
    t_stack b;


    init_stack(&a, ac);
    init_stack(&b, ac);
    while (ac-- > 1)
    {
        if (get_value(av[ac], &nb) || is_duplicate(&a, nb))
        {
            ft_putendl("error");
            return (1);
        }
        data.value = nb;
        ft_push(&a, &data);
    }
    set_positions(&a);
    // print_stack(&a, &b);
    if (a.top == 2)
    {
        sort_three(&a, &b);
    }
    if (a.top == 4)
    {
        sort_five(&a, &b);
    }
    // printf("------------------------\n");
    // selection_sort(&a);
    // while (i <= a.top)
    // {
    //     printf("%lld\n", a.arr[i].value);
    //     i++;
    // }
    free(a.arr);
    free(b.arr);
    return 0;
}
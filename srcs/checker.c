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

int is_sorted(t_stack *a, t_stack *b)
{
    int i;

    i = 0;
    if (b->top != -1)
        return(FALSE);
    while (i <= a->top)
    {
        if (a->arr[i].position != i)
            return (FALSE);
        i++;
    }
    return (TRUE);
}       

int main(int ac, char **av)
{
    int count = 0;
    int nb;
    char *inst;

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
        print_stack(&a, &b);
    while (get_next_line(0, &inst) > 0)
    {
        if (apply_instuction(&a, &b, inst, 1))
        {
            ft_putstr("error\n");
            free(a.arr);
            free(b.arr);
            return (1);
        }
        count++;
        print_stack(&a, &b);
    }
    printf("you made %d instructions\n", count);
    if (is_sorted(&a, &b))
        ft_putstr("OK");
    else
        ft_putstr("KO");
    // i = a.top;
    // while (i >= 0)
    // {
    //     printf("%lld --- %lld\n", a.arr[i].value, a.arr[i].position);
    //     i--;
    // }
    // apply_instuction(&a, &b, "ra", 0);
    // printf("*******\n");
    // printf("*******\n");
    // i = a.top;
    // while (i >= 0)
    // {
    //     printf("%lld --- %lld\n", a.arr[i].value, a.arr[i].position);
    //     i--;
    // }
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
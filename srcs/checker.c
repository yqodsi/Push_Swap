#include "push_swap.h"

int is_sorted(t_stack *a, t_stack *b)
{
    int i;
    
    
    if (b->top != -1)
        return(FALSE);
    while (i < a->top)
    {
        if (a->arr[a->[]])
    }
}

int main(int ac, char **av)
{

    int i;
    int nb;
    char *inst;

    t_data data;
    t_stack a;
    t_stack b;

    i = 0;
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
    while (get_next_line(0, &inst) > 0)
    {
        if (apply_instuction(&a, &b, inst, 0))
        {
            ft_putstr("error\n");
            free(&a.arr);
            free(&b.arr);
            return (1);
        }
    }
    
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
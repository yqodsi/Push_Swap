#include "push_swap.h"

typedef struct s_data
{
    int value;
    int position;
} t_data;

typedef struct s_stack
{
    t_data *arr;
    int top;
} t_stack;

void init_stack(t_stack *stack, int len)
{
    stack->top = -1;
    stack->arr = malloc(sizeof(t_data) * len);
}

void ft_push(t_stack *stack, t_data *data)
{

    stack->top++;
    stack->arr[stack->top].position = data->position;
    stack->arr[stack->top].value = data->value;
}

int is_empty(t_stack *stack)
{
    if (stack->top == -1)
        return (TRUE);
    return (FALSE);
}

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

t_data *ft_pop(t_stack *stack)
{

    stack->top--;
    return (&stack->arr[stack->top + 1]);
}

void ft_swap(t_data *data1, t_data *data2)
{
    int value;
    int position;

    value = data1->value;
    position = data1->position;

    data1->value = data2->value;
    data1->position = data2->position;

    data2->value = value;
    data2->position = position;
}

void selection_sort(t_stack *stack)
{
    int i, j, min;

    i = 0;
    while (i <= stack->top)
    {
        min = i;
        j = i;
        while (j <= stack->top)
        {
            if (stack->arr[j].value < stack->arr[min].value)
                min = j;
            j++;
        }
        ft_swap(&stack->arr[min], &stack->arr[i]);
        i++;
    }
}

void set_positions(t_stack *stack)
{
    t_stack tmp;
    int i;
    int j;

    i = 0;
    tmp.arr = malloc(sizeof(t_data) * (stack->top + 1));
    ft_memmove(tmp.arr, stack->arr, sizeof(t_data) * (stack->top + 1));
    tmp.top = stack->top;
    selection_sort(&tmp);

    while (i <= tmp.top)
    {
        j = 0;
        while (j <= tmp.top)
        {
            if (stack->arr[i].value == tmp.arr[j].value)
                stack->arr[i].position = j;
            j++;
        }
        i++;
    }
    free(tmp.arr);
}

int apply_instuction(t_stack *a, t_stack *b, char *inst, int print)
{
    if (!ft_strcmp("sa", inst))
        sa_instruction(a, b);
    else if (!ft_strcmp("sb", inst))
        sb_instruction(a, b);
    else if (!ft_strcmp("ss", inst))
        ss_instruction(a, b);
    else if (!ft_strcmp("pa", inst))
        pa_instruction(a, b);
    else if (!ft_strcmp("pb", inst))
        pb_instruction(a, b);
    else if (!ft_strcmp("ra", inst))
        ra_instruction(a, b);
    else if (!ft_strcmp("rb", inst))
        rb_instruction(a, b);
    else if (!ft_strcmp("rr", inst))
        rr_instruction(a, b);
    else if (!ft_strcmp("rra", inst))
        rra_instruction(a, b);
    else if (!ft_strcmp("rrb", inst))
        rrb_instruction(a, b);
    else if (!ft_strcmp("rrr", inst))
        rrr_instruction(a, b);
}

int main(int ac, char **av)
{

    int i;
    int nb;

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
    while (i <= a.top)
    {
        printf("%d --- %d\n", a.arr[i].value, a.arr[i].position);
        i++;
    }
    // i = 0;
    // printf("------------------------\n");
    // selection_sort(&a);
    // while (i <= a.top)
    // {
    //     printf("%d\n", a.arr[i].value);
    //     i++;
    // }
    free(a.arr);
    free(b.arr);
    return 0;
}
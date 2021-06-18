#include "push_swap.h"

void sort_three(t_stack *a, t_stack *b)
{
    if (a->arr[0].position == 0)
    {
        if (a->arr[1].position != 1)
            apply_instuction(a, b, "sa", 1);
    }
    else if (a->arr[1].position == 0)
    {
        apply_instuction(a, b, "rra", 1);
        if (a->arr[1].position != 1)
            apply_instuction(a, b, "sa", 1);
    }
    else
    {
        apply_instuction(a, b, "ra", 1);
        if (a->arr[1].position != 1)
            apply_instuction(a, b, "sa", 1);
    }
}

void    sort_five(t_stack *a, t_stack *b)
{
    int c;
    int top;

    c = 0;
    top = a->top;
    while (c != 2)
    {
        if (a->arr[a->top].position == top || a->arr[a->top].position == top - 1)
        {
            apply_instuction(a, b, "pb", 1);
            c++;
        }
        apply_instuction(a, b, "ra", 1);
    }
    sort_three(a, b);
    apply_instuction(a, b, "pa", 1);
    apply_instuction(a, b, "pa", 1);
    if (a->arr[a->top].position != a->top)
        apply_instuction(a, b, "sa", 1);
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
            if (stack->arr[j].value > stack->arr[min].value)
                min = j;
            j++;
        }
        ft_swap(&stack->arr[min], &stack->arr[i]);
        i++;
    }
}
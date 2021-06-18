#include "push_swap.h"

t_data *ft_pop(t_stack *stack)
{

    stack->top--;
    return (&stack->arr[stack->top + 1]);
}

void ft_push(t_stack *stack, t_data *data)
{

    stack->top++;
    stack->arr[stack->top].position = data->position;
    stack->arr[stack->top].value = data->value;
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

void init_stack(t_stack *stack, int len)
{
    stack->top = -1;
    stack->arr = malloc(sizeof(t_data) * len);
}

int is_empty(t_stack *stack)
{
    if (stack->top == -1)
        return (TRUE);
    return (FALSE);
}
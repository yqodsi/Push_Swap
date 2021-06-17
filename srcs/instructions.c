#include "push_swap.h"

void sab_instruction(t_stack *stack)
{
    if (stack->top <= 0)
        return;
    ft_swap(&stack->arr[stack->top], &stack->arr[stack->top - 1]);
}

void ra_instruction(t_stack *stack)
{
    t_data tmp;
    // tmp = stack->arr[stack->top];
    ft_memmove(&tmp, &stack->arr[stack->top], sizeof(t_data));
    ft_memmove(stack->arr + 1, stack->arr, sizeof(t_data) * stack->top);
    // stack->arr[0] = tmp;
    ft_memmove(&stack->arr[0],&tmp,  sizeof(t_data));
}
#include "push_swap.h"


int apply_instuction(t_stack *a, t_stack *b, char *inst, int display)
{
    if (!ft_strcmp("sa", inst))
        sab_instruction(a);
    else if (!ft_strcmp("sb", inst))
        sab_instruction(b);
    else if (!ft_strcmp("ss", inst))
    {
        sab_instruction(a);
        sab_instruction(b);
    }
    else if (!ft_strcmp("pa", inst))
        ft_push(a, ft_pop(b));
    else if (!ft_strcmp("pb", inst))
        ft_push(b, ft_pop(a));
    else if (!ft_strcmp("ra", inst))
        rab_instruction(a);
        else if (!ft_strcmp("rb", inst))
            rab_instruction(b);
        else if (!ft_strcmp("rr", inst))
        {
            rab_instruction(a);
            rab_instruction(b);
        }
        else if (!ft_strcmp("rra", inst))
            rrab_instruction(a);
        else if (!ft_strcmp("rrb", inst))
            rrab_instruction(b);
        else if (!ft_strcmp("rrr", inst))
        {
            rrab_instruction(a);
            rrab_instruction(b);

        }
    else
        return (ERROR);
    if (display)
        ft_putendl(inst);
    return (SUCCESS);
}

void sab_instruction(t_stack *stack)
{
    if (stack->top <= 0)
        return;
    ft_swap(&stack->arr[stack->top], &stack->arr[stack->top - 1]);
}

void rab_instruction(t_stack *stack)
{
    t_data tmp;
    // tmp = stack->arr[stack->top];
    ft_memmove(&tmp, &stack->arr[stack->top], sizeof(t_data));
    ft_memmove(stack->arr + 1, stack->arr, sizeof(t_data) * stack->top);
    // stack->arr[0] = tmp;
    ft_memmove(&stack->arr[0],&tmp,  sizeof(t_data));
}

void rrab_instruction(t_stack *stack)
{
    t_data tmp;
    // tmp = stack->arr[stack->top];
    ft_memmove(&tmp, &stack->arr[0], sizeof(t_data));
    ft_memmove(stack->arr, stack->arr + 1, sizeof(t_data) * stack->top);
    // stack->arr[0] = tmp;
    ft_memmove(&stack->arr[stack->top],&tmp,  sizeof(t_data));
}


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft.h"
#define SUCCESS 0
#define ERROR 1

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

void    ft_swap(t_data *data1, t_data *data2);
void    sab_instruction(t_stack *stack);
void    ra_instruction(t_stack *stack);
int     apply_instuction(t_stack *a, t_stack *b, char *inst, int display);
t_data *ft_pop(t_stack *stack);
void    ft_push(t_stack *stack, t_data *data);
void    rrab_instruction(t_stack *stack);
void    rab_instruction(t_stack *stack);

void    set_positions(t_stack *stack);
void    selection_sort(t_stack *stack);
void init_stack(t_stack *stack, int len);
int get_value(char *str, int *nb);
int is_duplicate(t_stack *stack, int nb);
void sort_three(t_stack *a, t_stack *b);
void    sort_five(t_stack *a, t_stack *b);

#endif
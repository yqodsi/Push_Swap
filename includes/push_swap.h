#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft.h"
#define SUCCESS 0
#define ERROR 1

typedef struct s_data
{
    long long int value;
    long long int position;

} t_data;

typedef struct s_stack
{
    t_data *arr;
    int top;
} t_stack;

void ft_swap(t_data *data1, t_data *data2);
void sab_instruction(t_stack *stack);
void ra_instruction(t_stack *stack);
int apply_instuction(t_stack *a, t_stack *b, char *inst, int display);

#endif
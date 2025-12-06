#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>    // malloc, free, NULL
# include <unistd.h>    // write
# include <limits.h>    // INT_MAX, INT_MIN

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
} t_stack;

void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);

#endif
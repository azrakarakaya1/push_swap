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

void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);

void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);

void error_exit(void);
void add_node_end(t_stack **stack, t_stack *new_node);
void radix_sort(t_stack **a, t_stack **b);
void init_a(t_stack **a, char **argv);
void simple_sort(t_stack **a, t_stack **b);
int stack_size(t_stack *stack);
int check_dup(t_stack *a, int n);
int is_sorted(t_stack *stack);
long ft_atol(const char *str);
t_stack *new_node(int value);
t_stack *last_node(t_stack *head);

#endif
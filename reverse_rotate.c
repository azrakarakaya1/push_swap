#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *second_to_last;

    if (!*stack || !(*stack)->next)
        return ;
    second_to_last = *stack;
    while (second_to_last->next->next)
        second_to_last = second_to_last->next;
    last = second_to_last->next;
    second_to_last->next = NULL;
    last->next = *stack;
    *stack = last;
}

void rra(t_stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
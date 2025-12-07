#include "push_swap.h"

static void push(t_stack **src, t_stack **dest)
{
    t_stack *push_node;

    if (!*src)
        return ;
    push_node = *src;
    *src = (*src)->next;
    if (!*dest)
    {
        *dest = push_node;
        push_node->next = NULL;
    }
    else
    {
        push_node->next = *dest;
        *dest = push_node;
    }
}

void pa(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pa\n", 4);
}

void pb(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}
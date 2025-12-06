#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int check_dup()
{

}

void init_a(t_stack **a, char **argv)
{
    long n;
    int i;

    i = 1;
    while (argv[i])
    {
        n = atol(argv[i]);
        if (n > 2147483647 || n < -2147483648)
            error_exit();
        if (check_dup(*a, (int)n))
            error_exit();

        // STACK ADD BACK FUNC
    }
    // ASSIGN INDEXES
}


#include "push_swap.h"

void index_a(t_stack *a)
{
    t_stack *initial;
    t_stack *loop;
    int count;

    count = 0;
    initial = a;
    while (initial)
    {
        count = 0;
        loop = a;
        while (loop)
        {
            if (loop->value < initial->value)
                count++;
            loop = loop->next;
        }
        initial->value = count;
        initial = initial->next;
    }
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
        add_node_end(a, new_node((int)n));
    }
    index_a(*a);
}


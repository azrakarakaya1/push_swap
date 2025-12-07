#include "push_swap.h"

void index_a()
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


#include "push_swap.h"

void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

int check_dup(t_stack *a, int n)
{
    t_stack *tmp;

    tmp = a;
    while (tmp)
    {
        if (tmp->value == n)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int ft_atol(const char *str)
{
    int i;
    int sign;
    long result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}


/*
    argc = argument count, program adı dahil toplam argüman sayısı
    argv = argument vector, argümanları tutan bir dizi
    argv[0] = program adı
    argv[argc-1] = son argüman
    argv[argc] = her zaman NULL
*/
#include "push_swap.h"

static void free_stack(t_stack **stack)
{
    t_stack *head;
    t_stack *temp;

    if (!stack || !*stack)
        return ;
    head = *stack;
    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    *stack = NULL;
}

int main(int argc, char **argv)
{
    int n;
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    n = argc - 1;
    if (argc < 2)
        return (0);
    init_a(&a, argv);
    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }
    if (argc <= 6)
        simple_sort(&a, &b);
    else
        radix_sort(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
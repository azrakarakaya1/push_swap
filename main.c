/*
    argc = argument count, program adı dahil toplam argüman sayısı
    argv = argument vector, argümanları tutan bir dizi
    argv[0] = program adı
    argv[argc-1] = son argüman
    argv[argc] = her zaman NULL
*/
#include "push_swap.h"

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
    
    
    

}
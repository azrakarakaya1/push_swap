/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:34:10 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/08 12:34:13 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*temp;

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

int	main(int argc, char **argv)
{
	int		n;
	t_stack	*a;
	t_stack	*b;

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
	if (stack_size(a) <= 5)
		simple_sort(&a, &b);
	else
		radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

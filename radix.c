/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:35:50 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/08 12:35:53 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	move_node(t_stack **a, t_stack **b, int shift_bit, int size)
{
	int		j;
	t_stack	*head;

	j = 0;
	head = *a;
	while (j < size)
	{
		head = *a;
		if (((head->index >> shift_bit) & 1) == 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	size;
	int	max_bits;

	i = 0;
	max_bits = get_max_bits(a);
	size = stack_size(*a);
	while (i < max_bits)
	{
		if (is_sorted(*a) && stack_size(*b) == 0)
			break ;
		move_node(a, b, i, size);
		while (stack_size(*b) != 0)
			pa(a, b);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:36:41 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/08 12:36:45 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index_pos(t_stack *stack, int index)
{
	int	p;

	p = 0;
	while (stack)
	{
		if (stack->index == index)
			return (p);
		p++;
		stack = stack->next;
	}
	return (-1);
}

static void	sort_three(t_stack **a)
{
	t_stack	*head;
	int		max;

	head = *a;
	max = head->index;
	if (head->next->index > max)
		max = head->next->index;
	if (head->next->next->index > max)
		max = head->next->next->index;
	if ((*a)->index == max)
		ra(a);
	else if ((*a)->next->index == max)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

static void	sort_four(t_stack **a, t_stack **b)
{
	int	min_index_pos;

	min_index_pos = get_index_pos(*a, 0);
	if (min_index_pos <= 2)
		while ((*a)->index != 0)
			ra(a);
	else
		while ((*a)->index != 0)
			rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

static void	sort_five(t_stack **a, t_stack **b)
{
	int	min_index_pos;
	int	second_min_pos;

	min_index_pos = get_index_pos(*a, 0);
	if (min_index_pos <= 2)
		while ((*a)->index != 0)
			ra(a);
	else
		while ((*a)->index != 0)
			rra(a);
	pb(a, b);
	second_min_pos = get_index_pos(*a, 1);
	if (second_min_pos <= 2)
		while ((*a)->index != 1)
			ra(a);
	else
		while ((*a)->index != 1)
			rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}

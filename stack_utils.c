/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:36:58 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/08 12:37:00 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*last_node(t_stack *head)
{
	t_stack	*last_node;

	last_node = head;
	if (!last_node)
		return (NULL);
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

void	add_node_end(t_stack **stack, t_stack *new_node)
{
	t_stack	*end;

	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	end = last_node(*stack);
	end->next = new_node;
}

int	stack_size(t_stack *stack)
{
	t_stack	*node;
	int		size;

	size = 0;
	node = stack;
	while (node)
	{
		node = node->next;
		size++;
	}
	return (size);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

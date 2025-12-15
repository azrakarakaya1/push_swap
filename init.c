/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:33:58 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/08 12:34:02 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (!argv)
		return ;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

static int	syntax_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	index_a(t_stack *a)
{
	t_stack	*initial;
	t_stack	*loop;
	int		count;

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
		initial->index = count;
		initial = initial->next;
	}
}

static void	process_args(t_stack **a, char **args)
{
	long	n;
	int		j;

	j = 0;
	while (args[j])
	{
		if (!syntax_check(args[j]))
		{
			free_matrix(args);
			error_exit(a);
		}
		n = ft_atol(args[j]);
		if (n > 2147483647 || n < -2147483648 || check_dup(*a, (int)n))
		{
			free_matrix(args);
			error_exit(a);
		}
		add_node_end(a, new_node((int)n));
		j++;
	}
}

void	init_a(t_stack **a, char **argv)
{
	int		i;
	char	**args;

	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			error_exit(a);
		process_args(a, args);
		free_matrix(args);
		i++;
	}
	index_a(*a);
}

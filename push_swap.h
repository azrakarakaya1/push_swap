/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:35:35 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/08 12:35:40 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **a);
void				ra(t_stack **a);
void				rra(t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

void				error_exit(t_stack **stack);
void				add_node_end(t_stack **stack, t_stack *new_node);
void				radix_sort(t_stack **a, t_stack **b);
void				init_a(t_stack **a, char **argv);
void				simple_sort(t_stack **a, t_stack **b);
void				free_stack(t_stack **stack);
int					stack_size(t_stack *stack);
int					check_dup(t_stack *a, int n);
int					is_sorted(t_stack *stack);
long				ft_atol(const char *str);
t_stack				*new_node(int value);
t_stack				*last_node(t_stack *head);
char				**ft_split(char const *s, char c);

#endif

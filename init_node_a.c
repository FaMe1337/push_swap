/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:07:48 by famendes          #+#    #+#             */
/*   Updated: 2024/10/10 16:32:17 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*tmp_b;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		tmp_b = b;
		while (tmp_b)
		{
			if (tmp_b->number < a->number && tmp_b->number > best_match)
			{
				best_match = tmp_b->number;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_biggest_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	push_cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->median))
			a->push_cost = len_a - a->index;
		if (a->target_node->median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - a->target_node->index;
		a = a->next;
	}
}

void	prepare_nodes_a(t_stack *a, t_stack *b)
{
	give_index(a);
	give_index(b);
	set_target_node_a(a, b);
	push_cost_a(a, b);
	set_cheapest(a);
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_number;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_number = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_number)
		{
			cheapest_number = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:39:42 by famendes          #+#    #+#             */
/*   Updated: 2024/10/09 22:12:11 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_smallest_node(t_stack *stack)
{
	t_stack *smallest_node;

	if (!stack)
		return(NULL);
	smallest_node = stack;
	while (stack)
	{
		if (smallest_node->number > stack->number)
			smallest_node = stack;
		stack = stack->next;
	}
	return (smallest_node);
}

static void	set_target_node_b(t_stack *a, t_stack *b)
{
	t_stack *target_node;
	t_stack	*tmp_a;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->number > b->number && tmp_a->number < best_match)
			{
				best_match = tmp_a->number;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_smallest_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void prepare_nodes_b(t_stack *a, t_stack *b)
{
	give_index(a);
	give_index(b);
	set_target_node_b(a, b);
}

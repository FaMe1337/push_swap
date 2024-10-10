/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:54:40 by famendes          #+#    #+#             */
/*   Updated: 2024/10/10 11:31:45 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_from_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->median && cheapest_node->target_node->median)
		rotate_both(a, b, cheapest_node);
	else if(!(cheapest_node->median)
		&& !(cheapest_node->target_node->median))
		reverse_rotate_both(a, b, cheapest_node);
	cheapest_on_top(a, cheapest_node, 'a');
	cheapest_on_top(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void push_from_b_to_a(t_stack **a, t_stack **b)
{
	cheapest_on_top(a, (*b)->target_node, 'a');
	pa(a,b);
}

static t_stack	*find_smallest_stack(t_stack *stack)
{
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->number < min_node->number)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

static void min_to_top(t_stack **a)
{
	t_stack	*min_node;

	min_node = find_smallest_stack(*a);
	while ((*a)->number != min_node->number)
	{
		if (min_node->median)
			ra(a);
		else
			rra(a);
	}
}

void	big_sort(t_stack **a, t_stack **b, int size)
{
	if (size-- > 3 && !sorted_stack(*a))
		pb(b, a);
	if (size-- > 3 && !sorted_stack(*a))
		pb(b, a);
	while (size-- > 3 && !sorted_stack(*a))
	{
		prepare_nodes_a(*a, *b);
		push_from_a_to_b(a, b);
	}
	small_sort(a);;
	while (*b)
	{
		prepare_nodes_b(*a, *b);
		push_from_b_to_a(a, b);
	}
	give_index(*a);
	min_to_top(a);
}


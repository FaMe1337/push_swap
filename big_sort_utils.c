/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:27:15 by famendes          #+#    #+#             */
/*   Updated: 2024/10/09 22:12:28 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_biggest_node(t_stack *b)
{
	t_stack *big_node;

	big_node = b;
	while (b)
	{
		if (b->number > big_node->number)
			big_node = b;
		b = b->next;
	}
	return (big_node);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return(NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void give_index(t_stack *stack)
{
	int	i;
	int median;

	i = 0;
	median = stack_size(stack) / 2;
	if (!stack)
		return;
	while(stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median = true;
		else
			stack->median = false;
		i++;
		stack = stack->next;
	}
}

void	cheapest_on_top(t_stack **stack,t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

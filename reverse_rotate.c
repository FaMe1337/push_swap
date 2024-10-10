/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:31:00 by famendes          #+#    #+#             */
/*   Updated: 2024/10/09 20:51:14 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tail = find_last_node(*stack);
	before_tail = tail->previous;
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	tmp->previous = *stack;
	(*stack)->previous = NULL;
	before_tail->next = NULL;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	ft_printf("%s\n", "rra");
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf("%s\n", "rrb");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("%s\n", "rrr");
}

void reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	give_index(*a);
	give_index(*b);
}

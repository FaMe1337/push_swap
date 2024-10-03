/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:31:00 by famendes          #+#    #+#             */
/*   Updated: 2024/10/03 23:15:38 by famendes         ###   ########.fr       */
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

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_printf("%s\n", "rra");
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_printf("%s\n", "rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("%s\n", "rrr");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:05:41 by famendes          #+#    #+#             */
/*   Updated: 2024/10/04 17:43:54 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack *temp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	temp = *stack;
	tail = find_last_node(*stack);
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	temp->next = NULL;
	tail->next = temp;
	temp->previous = tail;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("%s\n", "ra");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("%s\n", "rb");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("%s\n", "rr");
}

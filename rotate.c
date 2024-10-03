/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:05:41 by famendes          #+#    #+#             */
/*   Updated: 2024/10/03 23:15:44 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack *temp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	tail = find_last_node(*stack);
	temp->next = NULL;
	tail->next = temp;
	temp->previous = tail;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("%s\n", "ra");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("%s\n", "rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("%s\n", "rr");
}

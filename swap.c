/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:57:34 by famendes          #+#    #+#             */
/*   Updated: 2024/10/08 17:59:19 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack *tmp;

	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	tmp->next = (*stack)->next;
	if (tmp->next)
		tmp->next->previous = tmp;
	tmp->previous = *stack;
	(*stack)->next = tmp;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("%s\n", "sa");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("%s\n", "sb");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("%s\n", "ss");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:36:52 by famendes          #+#    #+#             */
/*   Updated: 2024/10/08 22:16:53 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest_number(t_stack *stack)
{
	int n;

	n = stack->number;
	while (stack->next)
	{
		if (n < stack->next->number)
			n = stack->next->number;
		stack = stack->next;
	}
	return (n);
}

void small_sort(t_stack **a)
{
	int	bigger_number;

	bigger_number = find_biggest_number(*a);
	if (bigger_number == (*a)->number)
		ra(a);
	else if (bigger_number == (*a)->next->number)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}

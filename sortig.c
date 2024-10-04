/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:36:52 by famendes          #+#    #+#             */
/*   Updated: 2024/10/04 19:37:06 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void small_sort(t_stack **a)
{
	int	bigger_n;

	bigger_n = find_biggest(*a);
	printf(" bigger: %d\n", bigger_n);
	if (bigger_n == (*a)->number)
		ra(a);
	else if (bigger_n == (*a)->next->number)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}

int	find_biggest(t_stack *stack)
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

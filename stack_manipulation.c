/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:52:26 by famendes          #+#    #+#             */
/*   Updated: 2024/10/09 21:57:32 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack **a, t_stack **b, long *array, int size)
{
	*a = NULL;
	*b = NULL;
	int i;

	i = 0;
	while (i < size)
		append_node(a, (int)array[i++]);
	free(array);

}

void append_node(t_stack **a, int value)
{
	t_stack *new;
	t_stack *last_node;

	new = malloc(sizeof(t_stack));
	if (!new)
		error("Malloc for new node failed");
	new->number = value;
	new->cheapest = 0;
	//new->index = 0;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		new->previous = NULL;
	}
	else
	{
		last_node = find_last_node(*a);
		last_node->next = new;
		new->previous = last_node;
	}
}

t_stack	*find_last_node(t_stack *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

int stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

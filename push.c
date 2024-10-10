/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:56:52 by famendes          #+#    #+#             */
/*   Updated: 2024/10/10 16:39:23 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	if (!*dst)
	{
		*dst = tmp;
		(*dst)->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		(*dst)->previous = tmp;
		*dst = tmp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("%s\n", "pa");
}

void	pb(t_stack **b, t_stack **a)
{
	push(a, b);
	ft_printf("%s\n", "pb");
}

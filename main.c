/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:11 by famendes          #+#    #+#             */
/*   Updated: 2024/10/18 17:01:25 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	long	*array;

	size = 0;
	array = 0;
	if (ac < 2)
		return (0);
	else if (ac == 2)
		parsing_one_string(av, &array, &size);
	else
		parsing_n_string(av, &array, &size);
	stack_init(&a, &b, array, size);
	if (!sorted_stack(a))
	{
		if (size == 2)
			sa(&a);
		else if (size == 3)
			small_sort(&a);
		else
			big_sort(&a, &b, size);
	}
	free_stack(&a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:11 by famendes          #+#    #+#             */
/*   Updated: 2024/10/01 23:35:12 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	int size;
	long *array;

	if (ac < 2)
		error("Not enough arguments");
	else if (ac == 2)
		parsing_one_string(av, &array, &size);
	else
		parsing_n_string(av, &array, &size);
	for(int j = 0; j < size; j++)
		printf("%ld\n", array[j]);
	printf("%d", size);
	//tenho array allocado, lembrar de apagar
	stack_init(&a, &b, array);
}

void	stack_init(t_stack **a, t_stack **b, long *array)
{
	*a = NULL;
	*b = NULL;

	append_node(a, array);
}

void append_node(t_stack **a, long *array)
{
	t_stack new;

	new = malloc(sizeof(t_stack))
	if (!new)
		error("Malloc for new node failed")
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:11 by famendes          #+#    #+#             */
/*   Updated: 2024/10/01 19:41:07 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void stack_init(t_stack **a, char **av)
{
	int *numbers;
	char **split;
	int i;

	i = 0;
	split = ft_split
	numbers = malloc(sizeof(int))
} */

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	int i;
	long *array;

	i = 1;
	if (ac < 2)
		error("Not enough arguments");
	else if (ac == 2)
	{
		verify_av(av);
		verify_if_number(av[1]);
		array = copy_to_array_if_one_str(av[1]);
	}
	else if (ac > 2)
	{
		while (av[i])
			verify_if_number(av[i++]);
		array = copy_numbers_to_array_if_m_str(av);
	}
	//tenho array allocado, lembrar de apagar
	stack_init(&a, &b, array);
}

int	error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}

void	stack_init(t_stack **a, t_stack **b, long *array)
{
	a = NULL;
	b = NULL;

	append_node(a, )
}

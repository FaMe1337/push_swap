/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:11 by famendes          #+#    #+#             */
/*   Updated: 2024/10/01 16:42:20 by famendes         ###   ########.fr       */
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

	a = NULL;
	b = NULL;
	i = 1;
	if (ac < 2)
		error("Not enough arguments");
	else if (ac == 2)
	{
		verify_av(av);
		verify_if_number(av[1]);
		array = copy_to_array(av[1]);
	}
	else if (ac > 2)
	{
		while (av[i])
		{
			verify_if_number(av[i]);
			i++;
		} 
	}
	// agora copiar verificar se tenho ints > ou < que INT_MAX e INT_MIN e se tenho repetidos
	//stack_init(&a, av);
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:11 by famendes          #+#    #+#             */
/*   Updated: 2024/09/26 17:49:42 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	char *numbers;
	
	if (ac < 2)
		error("Not enough arguments");
	if (ac == 2)
	{
		copy_str(&a, av[1]);
	}
	else
}

void copy_str(t_stack **a, char *av)
{
	char *numbers;
	int i;
	
	numbers = ft_split(av, ' ');
	while (numbers[i])
	{
		a = malloc(sizeof(t_stack));
	}
}

int error(char *error_message)
{
	ft_printf("%s", error_message);
	exit(1);
}


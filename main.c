/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:11 by famendes          #+#    #+#             */
/*   Updated: 2024/09/29 16:08:02 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void verify_av(char **av)
{
	char **numbers;
	int i = 0;

	numbers = ft_split(av[1], ' ');
	if (!numbers[1])
	{
		free(numbers[0]);
		free(numbers);
		error("Not enough numbers");
	}
	free_split(numbers);
}

void verify_if_number(char *av)
{
	char **numbers;
	int j = 0;

	numbers = ft_split(av, ' ');
	while (numbers[j])
	{
		int i = 0;
		while (numbers[j][i])
		{
			if ((numbers[j][i] < '0' || numbers[j][i] > '9') && numbers[j][i] != '-')
				error("Input needs to be all numbers");
			else if (numbers[j][i] == '-' && (numbers[j][i + 1] < '0' || numbers[j][i + 1] > '9'))
				error("Input after - needs to be a number");
			printf("%c\n", numbers[j][i]);
			i++;
		}
		j++;
	}
	free_split(numbers);
}

int error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		error("Not enough arguments");
	if (ac == 2)
	{
		verify_av(av);
		verify_if_number(av[1]);
		//agora copiar
	}
	else if (ac > 2)
	

}

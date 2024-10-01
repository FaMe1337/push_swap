/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:39:39 by famendes          #+#    #+#             */
/*   Updated: 2024/10/01 19:33:11 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verify_av(char **av)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(av[1], ' ');
	if (!numbers[1])
	{
		free(numbers[0]);
		free(numbers);
		error("Not enough numbers");
	}
	free_split(numbers);
}

void	verify_if_number(char *av)
{
	char	**numbers;
	int		j;
	int		i;

	j = 0;
	numbers = ft_split(av, ' ');
	while (numbers[j])
	{
		i = 0;
		while (numbers[j][i])
		{
			verify_all_numbers(numbers, j, i);
			i++;
		}
		j++;
	}
	free_split(numbers);
}

void	verify_all_numbers(char **numbers, int j, int i)
{
	if ((numbers[j][i] < '0' || numbers[j][i] > '9')
			&& numbers[j][i] != '-')
	{
		free_split(numbers);
		error("Input needs to be all numbers");
	}
	else if (numbers[j][i] == '-' && (numbers[j][i + 1] < '0'
			|| numbers[j][i + 1] > '9'))
	{
		free_split(numbers);
		error("Input after - needs to be a number");
	}
}

long	*copy_to_array_if_one_str(char *av)
{
	char	**numbers;
	int		i;
	int		num_elements;
	long	*array;

	numbers = ft_split(av, ' ');
	num_elements = count_split(numbers);
	array = malloc(sizeof(int *) * num_elements);
	if (!array)
	{
		free_split(numbers);
		error("Malloc failed");
	}
	i = 0;
	while (numbers[i])
	{
		copy_numbers_to_array(numbers, array, i);
		i++;
	}
	free_split(numbers);
	for (int j = 0; j < num_elements; j++)
		printf("%ld\n", array[j]);
	return (array);
}

long	*copy_numbers_to_array_if_m_str(char **av)
{
	int i;
	int j;
	long *array;

	i = 0;
	j = 0;
	array = malloc(sizeof(long) * count_split(av) - 1);
	if (!array)
		error("Malloc failed");
	while (av[++i])
	{
		array[j] = ft_atoi(av[i]);
		if (array[j] > INT_MAX || array[j] < INT_MIN)
		{
			free(array);
			error("Number out of range");
		}
		if (repetition_verification(array, array[j], j))
		{
			free(array);
			error("Repeated number");
		}
		j++;
	}
	return (array);
}


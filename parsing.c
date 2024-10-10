/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:39:39 by famendes          #+#    #+#             */
/*   Updated: 2024/10/10 16:36:29 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verify_av(char **av)
{
	char	**numbers;

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

long	*copy_to_array_if_one_str(char *av, int *size)
{
	char	**numbers;
	int		i;
	long	*array;

	numbers = ft_split(av, ' ');
	*size = count_split(numbers);
	array = malloc(sizeof(long) * *size);
	if (!array)
	{
		free_split(numbers);
		error("Malloc for array of one string failed");
	}
	i = 0;
	while (numbers[i])
		copy_numbers_to_array(numbers, array, i++);
	free_split(numbers);
	return (array);
}

long	*copy_numbers_to_array_if_n_str(char **av, int *size)
{
	int		i;
	int		j;
	long	*array;

	i = 0;
	j = 0;
	array = malloc(sizeof(long) * (*size = count_split(av) - 1));
	if (!array)
		error("Malloc for array of n strings failed");
	while (av[++i])
	{
		array[j] = ft_atol(av[i]);
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

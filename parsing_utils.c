/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:46:11 by famendes          #+#    #+#             */
/*   Updated: 2024/10/10 16:02:23 by famendes         ###   ########.fr       */
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

int count_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	verify_all_numbers(char **numbers, int j, int i)
{
	if ((numbers[j][i] < '0' || numbers[j][i] > '9')
			&& numbers[j][i] != '-' && numbers[j][i] != '+')
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


void	copy_numbers_to_array(char **numbers, long *array, int i)
{
	array[i] = ft_atol(numbers[i]);
	if (array[i] > INT_MAX || array[i] < INT_MIN)
	{
		free(array);
		free_split(numbers);
		error("Number out of range");
	}
	if (repetition_verification(array, array[i], i))
	{
			free(array);
			error("Repeated number");
	}
}

int repetition_verification(long *array, long number, int j)
{
	int i;

	i = 0;
	while (i <= j - 1)
	{
		if (array[i] == number)
			return (1);
		i++;
	}
	return (0);
}

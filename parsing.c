/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:39:39 by famendes          #+#    #+#             */
/*   Updated: 2024/10/22 00:20:11 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verify_av(char **av)
{
	char	**numbers;

	numbers = ft_split(av[1], ' ');
	if (!numbers[0])
	{
		free_split(numbers);
		exit (0);
	}
	else if (!numbers[1])
	{
		verify_all_numbers(numbers, 0, 0);
		free_split(numbers);
		exit (0);
	}
	free_split(numbers);
}

void	verify_if_number(char *av)
{
	char	**numbers;
	int		j;
	int		i;

	j = 0;
	if (!*av)
		error("Error");
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
void	verify_if_number_in_n_string(char *av, char **numbers)
{
	int		j;
	int		i;

	j = 0;
	if (!*av)
	{
		free_split(numbers);
		error("Error");
	}
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
		return (NULL);
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

	i = -1;
	j = 0;
	array = malloc(sizeof(long) * (*size = count_split(av)));
	while (av[++i])
	{
		array[j] = ft_atol(av[i]);
		if (array[j] > INT_MAX || array[j] < INT_MIN)
		{
			free(array);
			free_split(av);
			error("Error");
		}
		if (repetition_verification(array, array[j], j))
		{
			free(array);
			free_split(av);
			error("Error");
		}
		j++;
	}
	return (array);
}


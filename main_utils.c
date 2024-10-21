/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:42:34 by famendes          #+#    #+#             */
/*   Updated: 2024/10/22 00:15:34 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(char *error_message)
{
	ft_putstr_fd(error_message, 2);
	ft_printf("\n");
	exit(1);
}

void	parsing_one_string(char **av, long **array, int *size)
{
	verify_av(av);
	verify_if_number(av[1]);
	*array = copy_to_array_if_one_str(av[1], size);
}

void	parsing_n_string(char **av, long **array, int *size)
{
    int	i;
	int	total_len;
    char	*all_args_concat;
    char	**numbers;

	i = 0;
	total_len = 0;
    while (av[++i])
        total_len += ft_strlen(av[i]) + 1;
    all_args_concat = malloc(total_len * sizeof(char));
    all_args_concat[0] = '\0';
    i = 0;
	while (av[++i])
    {
        ft_strcat(all_args_concat, av[i]);
        if (av[i + 1])
            ft_strcat(all_args_concat, " ");
	}
	numbers = ft_split(all_args_concat, ' ');
	free(all_args_concat);
	i = 0;
	while (av[++i])
		verify_if_number_in_n_string(av[i], numbers);
    *array = copy_numbers_to_array_if_n_str(numbers, size);
	free_split(numbers);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	sorted_stack(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

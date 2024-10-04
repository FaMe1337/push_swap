/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 22:42:34 by famendes          #+#    #+#             */
/*   Updated: 2024/10/04 19:22:26 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(char *error_message)
{
	ft_printf("%s\n", error_message);
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

	i = 1;
	while (av[i])
		verify_if_number(av[i++]);
	*array = copy_numbers_to_array_if_n_str(av, size);

}

void	free_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int 	sorted_stack(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (1);
		stack = stack->next;
	}
	ft_printf("%s\n", "Stack is sorted");
	return (0);
}

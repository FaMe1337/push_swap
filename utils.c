/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:46:11 by famendes          #+#    #+#             */
/*   Updated: 2024/10/01 15:47:36 by famendes         ###   ########.fr       */
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

int error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}
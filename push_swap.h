#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "printf/ft_printf.h"
# include "Libft/libft.h"

typedef struct s_stack
{
	int	number;
	struct s_list *previous;
	struct s_list *next;
}				t_stack;

//utils
int		error(char *error_message);
void	free_split(char **split);
int		count_split(char **split);
void	copy_numbers_to_array(char **numbers, long *array, int i);
int		repetition_verification(long *array, long number, int j);

//parsing
void	verify_av(char **av);
void	verify_if_number(char *av);
long 	*copy_to_array_if_one_str(char *av);
long	*copy_numbers_to_array_if_m_str(char **av);
void 	verify_all_numbers(char **numbers, int j, int i);

#endif

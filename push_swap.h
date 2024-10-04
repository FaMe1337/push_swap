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
	struct s_stack *previous;
	struct s_stack *next;
}				t_stack;

// parsing utils
void	free_split(char **split);
int		count_split(char **split);
void	copy_numbers_to_array(char **numbers, long *array, int i);
int		repetition_verification(long *array, long number, int j);
void 	verify_all_numbers(char **numbers, int j, int i);

//parsing
void	verify_av(char **av);
void	verify_if_number(char *av);
long	*copy_to_array_if_one_str(char *av, int *size);
long	*copy_numbers_to_array_if_n_str(char **av, int *size);

//main utils
int		error(char *error_message);
void	parsing_one_string(char **av, long **array, int *size);
void	parsing_n_string(char **av, long **array, int *size);
int 	sorted_stack(t_stack *stack);
void	free_stack(t_stack **stack);

//stack_init
void	stack_init(t_stack **a, t_stack **b, long *array, int size);
void	append_node(t_stack **a, int value);
t_stack	*find_last_node(t_stack *node);

//rotate
//void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

//push
void	push(t_stack **src, t_stack **dst);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

//swap
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

//reverse rotate
//void	rev_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//sorting
void	small_sort(t_stack **a);
int		find_biggest(t_stack *stack);

#endif

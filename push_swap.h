#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "printf/ft_printf.h"
# include "Libft/libft.h"


typedef struct s_stack
{
	int	number;
	int	index;
	int	push_cost;
	bool	median;
	bool cheapest;
	struct s_stack *target_node;
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
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);


//push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

//swap
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

//reverse rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);


//sorting
void	small_sort(t_stack **a);
void	big_sort(t_stack **a, t_stack **b, int size);

//big sort utils
t_stack *find_biggest_node(t_stack *b);
int		stack_size(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void	give_index(t_stack *stack);
void	cheapest_on_top(t_stack **stack,t_stack *top_node, char stack_name);


//prepare a stack
void	prepare_nodes_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);

//prepare b stack
void	prepare_nodes_b(t_stack *a, t_stack *b);

#endif

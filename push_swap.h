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
	struct s_list *next;
}				t_stack;


int error(char *error_message);

#endif
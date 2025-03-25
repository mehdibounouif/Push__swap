/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:23:48 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/20 18:24:05 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
//# include <stdio.h>
# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				cost;
	int				rank;
	bool			bellow_mid;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

// Print Error :

void	ft_error(t_stack **a);

// Check list :

int		ft_check_dup(t_stack *stack);
int		ft_check_sorted(t_stack *stack);

// Parssing data :

t_stack	*handel_args(char **v);

// Dealing with list :

t_stack	*ft_last_node(t_stack *lst);
t_stack	*ft_new_node(int content);
void	ft_add_back(t_stack **stack, t_stack *new);
int		ft_list_size(t_stack *lst);
int		max_value(t_stack *stack);
int		min_value(t_stack *stack);
t_stack	*find_min(t_stack **stack);

// free :

void	ft_free_lst(t_stack **lst);
void	ft_free_str(char **arr);

// Operations :

void	swap(t_stack **stack, int j);
void	rotate(t_stack **stack, int j);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, int j);
void	push(t_stack **dest, t_stack **src, int j);
void	reverse_rotate(t_stack **stack, int j);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, int j);

// Sort stack :

void	sort_stack(t_stack **a, t_stack **b);

// Move from a to b

void	init_a_b(t_stack **a, t_stack **b);
void	move_a_b(t_stack **a, t_stack **b);
void	cost(t_stack *a, t_stack *b);
void	excact_cost(t_stack *b);
void	node_position(t_stack *stack);
void	rank(t_stack **stack);

// Sort three

void	sort_there(t_stack **stack);

// Move from b to a

void	init_b_a(t_stack **b, t_stack **a);
void	move_b_a(t_stack **b, t_stack **a);
void	both_checker(t_stack **a, t_stack **b, t_stack *cheapest);
void	target(t_stack *a, t_stack *b);
void	last_move(t_stack **stack);
t_stack	*cheapest_cost(t_stack *b);

#endif

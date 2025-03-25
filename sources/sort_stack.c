/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:29:42 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/20 18:29:45 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_value(t_stack *stack)
{
	int	i;

	i = stack->data;
	while (stack)
	{
		if (stack->data > i)
			i = stack->data;
		stack = stack->next;
	}
	return (i);
}

t_stack	*find_min(t_stack **stack)
{
	t_stack	*a;
	t_stack	*min;
	long	tmp;

	a = *stack;
	tmp = LONG_MAX;
	while (a)
	{
		if (tmp > a->data)
		{
			tmp = a->data;
			min = a;
		}
		a = a->next;
	}
	return (min);
}

void	last_move(t_stack **stack)
{
	t_stack	*node;

	if (!stack || !*stack)
		return ;
	node = find_min(stack);
	node_position(*stack);
	while (node->index != 0)
	{
		reverse_rotate(stack, 1);
		node_position(*stack);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;

	size_a = ft_list_size(*a);
	while (size_a-- > 3)
	{
		init_a_b(a, b);
		move_a_b(a, b);
	}
	sort_there(a);
	size_b = ft_list_size(*b);
	while (size_b--)
	{
		init_b_a(b, a);
		move_b_a(b, a);
	}
	last_move(a);
}

void	sort_there(t_stack **stack)
{
	while (!ft_check_sorted(*stack))
	{
		if (ft_list_size(*stack) == 2)
			swap(stack, 1);
		else
		{
			if (max_value(*stack) == (*stack)->data)
				rotate(stack, 1);
			else if (max_value(*stack) == (*stack)->next->data)
				reverse_rotate(stack, 1);
			if ((*stack)->data > (*stack)->next->data)
				swap(stack, 1);
		}
	}
}

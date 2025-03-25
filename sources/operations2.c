/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:29:24 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/21 11:38:48 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack, int j)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
	else if (j == 1)
		write(1, "sa\n", 3);
}

void	rotate(t_stack **stack, int j)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = (*stack)->next;
	(tmp->next)->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
	else if (j == 1)
		write(1, "ra\n", 3);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, int j)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	rotate(stack_a, 2);
	rotate(stack_b, 2);
	if (j == 1)
		write(1, "rr\n", 3);
}

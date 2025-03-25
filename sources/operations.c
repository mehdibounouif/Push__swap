/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:29:13 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/20 18:29:16 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **dest, t_stack **src, int j)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
	else if (j == 1)
		write(1, "pa\n", 3);
}

void	reverse_rotate(t_stack **stack, int j)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp2 = *stack;
	tmp1 = *stack;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = *stack;
	while (tmp2->next != tmp1)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	*stack = tmp1;
	if (j == 0)
		write(1, "rrb\n", 4);
	else if (j == 1)
		write(1, "rra\n", 4);
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, int j)
{
	if (!stack_a || !*stack_b || !stack_b || !*stack_b)
		return ;
	reverse_rotate(stack_a, 2);
	reverse_rotate(stack_b, 2);
	if (j == 1)
		write(1, "rrr\n", 4);
}

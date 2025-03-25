/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:28:30 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/20 18:28:31 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	both_checker(t_stack **b, t_stack **a, t_stack *cheapest)
{
	if (!cheapest->bellow_mid && !cheapest->target->bellow_mid)
		while (cheapest != *b && cheapest->target != *a)
			rotate_both(a, b, 1);
	if (cheapest->bellow_mid && cheapest->target->bellow_mid)
		while (cheapest != *b && cheapest->target != *a)
			reverse_rotate_both(a, b, 1);
}

void	move_b_a(t_stack **b, t_stack **a)
{
	t_stack	*current_b;

	current_b = cheapest_cost(*b);
	both_checker(b, a, current_b);
	node_position(*a);
	node_position(*b);
	while (current_b != *b)
	{
		if (!current_b->bellow_mid)
			rotate(b, 0);
		else
			reverse_rotate(b, 0);
	}
	while (current_b->target != *a)
	{
		if (!current_b->target->bellow_mid)
			rotate(a, 1);
		else
			reverse_rotate(a, 1);
	}
	push(a, b, 1);
}

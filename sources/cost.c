/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:26:07 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/20 18:26:08 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	excact_cost(t_stack *b)
{
	t_stack	*curr_b;
	int		cost_b;
	int		cost_target;

	curr_b = b;
	node_position(curr_b);
	while (curr_b)
	{
		cost_b = curr_b->cost;
		cost_target = curr_b->target->cost;
		curr_b->cost = cost_b + cost_target;
		if ((curr_b->bellow_mid && curr_b->target->bellow_mid)
			|| (!curr_b->bellow_mid && !curr_b->target->bellow_mid))
		{
			if (cost_b > cost_target)
				curr_b->cost = cost_b;
			else
				curr_b->cost = cost_target;
		}
		curr_b = curr_b->next;
	}
}

void	cost(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*curr_b;

	curr_a = a;
	node_position(a);
	while (curr_a)
	{
		if (curr_a->bellow_mid)
			curr_a->cost = (ft_list_size(a) - curr_a->index);
		else
			curr_a->cost = curr_a->index;
		curr_a = curr_a->next;
	}
	curr_b = b;
	node_position(b);
	while (curr_b)
	{
		if (curr_b->bellow_mid)
			curr_b->cost = (ft_list_size(b) - curr_b->index);
		else
			curr_b->cost = curr_b->index;
		curr_b = curr_b->next;
	}
	excact_cost(b);
}

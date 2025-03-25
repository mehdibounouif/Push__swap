/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:29:53 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/20 18:29:55 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	target(t_stack *b, t_stack *a)
{
	t_stack	*target_node;
	t_stack	*curr_a;
	long	tmp;
	long	diff;

	while (b != NULL)
	{
		(1) && (tmp = LONG_MIN, curr_a = a);
		while (curr_a != NULL)
		{
			if (b->data < curr_a->data)
			{
				diff = (b->data - curr_a->data);
				if (diff > tmp)
				{
					tmp = diff;
					target_node = curr_a;
				}
			}
			curr_a = curr_a->next;
		}
		if (tmp == LONG_MIN)
			target_node = find_min(&a);
		(1) && (b->target = target_node, b = b->next);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:30:11 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/20 18:30:12 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*cheapest_cost(t_stack *b)
{
	t_stack	*cheapest;
	int		tmp;

	tmp = b->cost;
	cheapest = b;
	while (b)
	{
		if (b->cost < tmp)
		{
			tmp = b->cost;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}

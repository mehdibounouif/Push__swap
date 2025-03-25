/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:28:59 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/21 16:00:08 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rank(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		count;

	current = *stack;
	while (current)
	{
		count = 0;
		compare = *stack;
		while (compare)
		{
			if (current->data > compare->data)
				count++;
			compare = compare->next;
		}
		current->rank = count;
		current = current->next;
	}
}

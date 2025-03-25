/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:28:43 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/20 18:28:45 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	node_position(t_stack *stack)
{
	int	i;
	int	size;
	int	mid;

	i = 0;
	size = ft_list_size(stack);
	mid = size / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->bellow_mid = false;
		else
			stack->bellow_mid = true;
		i++;
		stack = stack->next;
	}
}

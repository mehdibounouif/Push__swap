/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:25:26 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/20 18:25:58 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_dup(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (tmp->data == stack->data)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	ft_check_sorted(t_stack *stack)
{
	int	tmp;

	tmp = stack->data;
	while (stack)
	{
		if (tmp > stack->data)
			return (0);
		tmp = stack->data;
		stack = stack->next;
	}
	return (1);
}

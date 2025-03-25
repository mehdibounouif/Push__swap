/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <mbounoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:05:00 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/20 18:21:57 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
void	print_list(t_stack *list)
{
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}
*/

int	main(int c, char **v)
{
	t_stack	*a;
	t_stack	*b;

	if (c < 2)
		return (0);
	a = handel_args(v);
	if (!a || ft_check_dup(a))
		ft_error(&a);
	b = NULL;
	if (!ft_check_sorted(a))
		sort_stack(&a, &b);
	ft_free_lst(&a);
	return (0);
}

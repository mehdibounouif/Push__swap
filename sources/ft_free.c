/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:26:18 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/25 17:41:27 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_str(char **arr)
{
	char	*a;

	if (arr && *arr)
	{
		while (*arr)
		{
			a = *arr;
			arr++;
			free(a);
		}
	}
	else
		return ;
}

void	ft_free_lst(t_stack **lst)
{
	t_stack	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			(*lst)->data = 0;
			free(*lst);
			*lst = tmp;
		}
	}
}

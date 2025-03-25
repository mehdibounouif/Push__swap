/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:26:31 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/25 17:55:28 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(t_stack **a)
{
	write(2, "Error\n", 6);
	ft_free_lst(a);
	exit(1);
}
/*
void    print_stack(t_stack *stack)
{
        while (stack)
        {
                printf("%d ", stack->data);
                stack = stack->next;
        }
        printf("\n");
}
*/

static int	ft_allo(char *s, int *sign)
{
	int	i;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]))
	{
		if (s[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

static int	ft_my_atoi(char *s, t_stack **a, char **tmp)
{
	int				sign;
	int				i;
	long long int	res;

	res = 0;
	sign = 1;
	i = ft_allo(s, &sign);
	while (s[i])
	{
		res = (res * 10) + (s[i] - 48);
		if (((res * sign) > 2147483647
				|| (res * sign) < -2147483648) || !ft_isdigit(s[i]))
		{
			ft_free_str(tmp);
			free(tmp);
			ft_error(a);
		}
		i++;
	}
	return (res * sign);
}

t_stack	*handel_args(char **v)
{
	t_stack	*a;
	char	**tmp;

	int (i), (j), (f);
	(1) && (a = NULL, i = 0);
	while (v[i])
	{
		(1) && (tmp = ft_split(v[i], ' '), f = 0);
		if (tmp == NULL || *tmp == NULL)
		{
			ft_free_str(tmp);
			ft_error(&a);
			(free(tmp)), return (NULL);
		}
		while (tmp[f])
		{
			j = ft_my_atoi(tmp[f], &a, tmp);
			ft_add_back(&a, ft_new_node(j));
			f++;
		}
		ft_free_str(tmp);
		free(tmp);
		i++;
	}
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:26:31 by mbounoui          #+#    #+#             */
/*   Updated: 2025/03/25 20:58:11 by mbounoui         ###   ########.fr       */
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

void	add_to_stack(char **tmp, t_stack **a)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (tmp[i])
	{
		j = ft_my_atoi(tmp[i], a, tmp);
		ft_add_back(a, ft_new_node(j));
		i++;
	}
}

t_stack	*handel_args(char **v)
{
	t_stack	*a;
	char	**tmp;
	int		i;

	a = NULL;
	i = 1;
	while (v[i])
	{
		tmp = ft_split(v[i], ' ');
		if (tmp == NULL || *tmp == NULL)
		{
			ft_free_str(tmp);
			ft_error(&a);
			free(tmp);
			return (NULL);
		}
		add_to_stack(tmp, &a);
		ft_free_str(tmp);
		free(tmp);
		i++;
	}
	return (a);
}

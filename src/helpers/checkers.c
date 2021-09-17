/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:18 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/17 20:59:58 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	are_args_valid(char **argc, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		if (argc[i][j] == '\0')
			return (1);
		while (argc[i][j] != '\0')
		{
			if (argc[i][j] == '-' && argc[i][j + 1] != '\0'
				&& (ft_isdigit(argc[i][j + 1])))
			{
				j++;
				continue ;
			}
			if (!(ft_isdigit(argc[i][j])) && argc[i][j] != ' ')
				if (!(j == 0 && argc[i][j] == '-' && argc[i][j + 1] != '\0'))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	has_list_duplicates(t_node **stack_a, int num)
{
	t_node	*tmp;

	if (*stack_a == NULL)
		return (0);
	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (tmp->num == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_stack_b_invalid(t_node **stack_b)
{
	if (*stack_b == NULL)
		return (0);
	ft_lstclear(stack_b);
	return (ft_putstr_fd("Error", 1));
}

int	is_num_int(long long num)
{
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:58:58 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 17:59:13 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_rotation_count_desc(t_node **stack_b, int next_num)
{
	int	count;
	int	top;

	count = 0;
	top = get_value_by_index(stack_b, count);
	while (next_num < top)
	{
		count++;
		top = get_value_by_index(stack_b, count);
	}
	return (count);
}

int	get_reversal_count_desc(t_node **stack_b, int next_num)
{
	int	count;
	int	bottom;
	int	size;

	count = 0;
	size = ft_lstsize(*stack_b) - 1;
	bottom = get_value_by_index(stack_b, size);
	while (next_num > bottom)
	{
		count++;
		size--;
		bottom = get_value_by_index(stack_b, size);
	}
	return (count);
}

int	get_rotation_count_asc(t_node **stack_b, int next_num)
{
	int	count;
	int	top;

	count = 0;
	top = get_value_by_index(stack_b, count);
	while (next_num > top)
	{
		count++;
		top = get_value_by_index(stack_b, count);
	}
	return (count);
}

int	get_reversal_count_asc(t_node **stack_b, int next_num)
{
	int	count;
	int	bottom;
	int	size;

	count = 0;
	size = ft_lstsize(*stack_b) - 1;
	bottom = get_value_by_index(stack_b, size);
	while (next_num < bottom)
	{
		count++;
		size--;
		bottom = get_value_by_index(stack_b, size);
	}
	return (count);
}

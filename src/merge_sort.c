/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:50:51 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/17 21:01:20 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	route_til_index_on_top(t_node **stack_b, int index, t_data **data)
{
	int	size;
	int	half;

	if (*stack_b == NULL)
		return (0);
	size = ft_lstsize(*stack_b);
	half = size / 2;
	if (size < index)
		return (0);
	else if (half >= index)
		rotate_stack_n_times(stack_b, index, (*data)->rotate);
	else
		reverse_stack_n_times(stack_b, size - index, (*data)->reverse);
	return (0);
}

void	determine_fastest_route(t_node **stack_b, t_data **data)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if ((*data)->rotate_nr == 0 && (*data)->reverse_nr != 0)
		route_til_index_on_top(stack_b, size - (*data)->reverse_nr, data);
	else if ((*data)->rotate_nr != 0 && (*data)->reverse_nr == 0)
		route_til_index_on_top(stack_b, (*data)->rotate_nr, data);
	else if ((*data)->rotate_nr <= (*data)->reverse_nr)
		route_til_index_on_top(stack_b, (*data)->rotate_nr, data);
	else
		route_til_index_on_top(stack_b, size - (*data)->reverse_nr, data);
}

int	set_top_desc(t_node **stack, int next_num, t_data **data)
{
	int	index_min;
	int	index_max;
	int	min;
	int	max;

	index_min = get_index_of_min(stack);
	min = get_value_by_index(stack, index_min);
	index_max = get_index_of_max(stack);
	max = get_value_by_index(stack, index_max);
	if (next_num < min || next_num > max)
		return (route_til_index_on_top(stack, index_min + 1, data));
	(*data)->rotate_nr = get_rotation_count_desc(stack, next_num);
	(*data)->reverse_nr = get_reversal_count_desc(stack, next_num);
	determine_fastest_route(stack, data);
	return (0);
}

int	set_top_asc(t_node **stack, int next_num, t_data **data)
{
	int	index_min;
	int	index_max;
	int	min;
	int	max;

	index_min = get_index_of_min(stack);
	min = get_value_by_index(stack, index_min);
	index_max = get_index_of_max(stack);
	max = get_value_by_index(stack, index_max);
	if (next_num < min || next_num > max)
		return (route_til_index_on_top(stack, index_max + 1, data));
	(*data)->rotate_nr = get_rotation_count_asc(stack, next_num);
	(*data)->reverse_nr = get_reversal_count_asc(stack, next_num);
	determine_fastest_route(stack, data);
	return (0);
}

void	merge_sort(t_node **stack_a, t_node **stack_b, t_data **data)
{
	int	i;

	i = 1;
	while ((*data)->size-- > 0 && !(*stack_a)->sorted)
	{
		set_top_desc(stack_b, (*stack_a)->num, data);
		ft_push(stack_a, stack_b, "pb");
		if (i++ == (*data)->merge_size)
		{
			route_til_index_on_top(stack_b, get_index_of_max(stack_b), data);
			if ((*data)->size > 0)
			{
				push_stack_n_times(stack_b, stack_a, (*data)->merge_size, "pa");
				rotate_stack_n_times(stack_a, (*data)->merge_size, "ra");
			}
			i = 0;
		}
	}
}

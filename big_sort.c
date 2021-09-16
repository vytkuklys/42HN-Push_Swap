/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:48:07 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 18:16:34 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int circle_til_index_on_top(t_node **stack_b, int index, t_data **data)
{
	int size;
	int half;

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

void prepare_for_circling_desc(t_node **stack_b, int next_num, t_data **data)
{
	int	rotations;
	int	reversals;
	int	size;

	rotations = get_rotation_count_desc(stack_b, next_num);
	reversals = get_reversal_count_desc(stack_b, next_num);
	size = ft_lstsize(*stack_b);
	if (rotations == 0 && reversals != 0)
		circle_til_index_on_top(stack_b, size - reversals, data);
	else if (rotations != 0 && reversals == 0)
		circle_til_index_on_top(stack_b, rotations, data);
	else if (rotations <= reversals)
		circle_til_index_on_top(stack_b, rotations, data);
	else
		circle_til_index_on_top(stack_b, size - reversals, data);
}

void prepare_for_circling_asc(t_node **stack_b, int next_num, t_data **data)
{
	int	rotations;
	int	reversals;
	int	size;

	rotations = get_rotation_count_asc(stack_b, next_num);
	reversals = get_reversal_count_asc(stack_b, next_num);
	size = ft_lstsize(*stack_b);
	if (rotations == 0 && reversals != 0)
		circle_til_index_on_top(stack_b, size - reversals, data);
	else if (rotations != 0 && reversals == 0)
		circle_til_index_on_top(stack_b, rotations, data);
	else if (rotations <= reversals)
		circle_til_index_on_top(stack_b, rotations, data);
	else
		circle_til_index_on_top(stack_b, size - reversals, data);
}

void push_n_times(t_node **src, t_node **dest, int n, char *operation)
{
	t_node *current;

	if (*src == NULL)
		return ;
	current = (*src)->next;
	while (*src != NULL && n-- > 0)
	{
		(*src)->sorted = 1;
		ft_push(src, dest, operation);
		*src = current;
		if (current != NULL)
			current = current->next;
	}
}

int set_top_desc(t_node **stack, int next_num, t_data **data)
{
	int index_min;
	int index_max;
	int min;
	int max;

	index_min = get_index_of_min(stack);
	min = get_value_by_index(stack, index_min);
	index_max = get_index_of_max(stack);
	max = get_value_by_index(stack, index_max);
	if (next_num < min || next_num > max)
		return circle_til_index_on_top(stack, index_min + 1, data);
	prepare_for_circling_desc(stack, next_num, data);
	return (0);
}

int set_top_asc(t_node **stack, int next_num, t_data **data)
{
	int index_min;
	int index_max;
	int min;
	int max;

	index_min = get_index_of_min(stack);
	min = get_value_by_index(stack, index_min);
	index_max = get_index_of_max(stack);
	max = get_value_by_index(stack, index_max);
	if (next_num < min || next_num > max)
		return circle_til_index_on_top(stack, index_max + 1, data);
	prepare_for_circling_asc(stack, next_num, data);
	return (0);
}

int sort_big_stack(t_node **stack_a, t_node **stack_b, t_data **data)
{
	t_node *current;
	t_node *next;
	int i;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	i = 1;
	current = *stack_a;
	next = (*stack_a)->next;
	while ((*data)->size-- > 0 && !(*stack_a)->sorted)
	{
		set_top_desc(stack_b, (*stack_a)->num, data);
		ft_push(stack_a, stack_b, "pb");
		if (i++ == (*data)->merge_size)
		{
			circle_til_index_on_top(stack_b, get_index_of_max(stack_b), data);
			if ((*data)->size > 0)
			{
				push_n_times(stack_b, stack_a, (*data)->merge_size, "pa");
				rotate_stack_n_times(stack_a, (*data)->merge_size, "ra");
			}
			i = 0;
		}
	}
	i = 0;
	while(i++ < (*data)->breakpoint && *stack_a)
	{
		set_top_desc(stack_b, (*stack_a)->num, data);
		ft_push(stack_a, stack_b, "pb");
	}
	circle_til_index_on_top(stack_b, get_index_of_max(stack_b), data);
	(*data)->reverse = "rra";
	(*data)->rotate = "ra";
	while ((*stack_b) != NULL)
	{
		set_top_asc(stack_a, (*stack_b)->num, data);
		ft_push(stack_b, stack_a, "pa");
	}
	circle_til_index_on_top(stack_a, get_index_of_min(stack_a), data);
	ft_lstprint(*stack_b);
	return (1);
}

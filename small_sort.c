/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:51:55 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 17:53:25 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_smaller_num_count(t_node **stack_a, int next_num)
{
	t_node	*tmp;
	int		count;

	if (*stack_a == NULL && (*stack_a)->next != NULL)
		return (0);
	count = 0;
	tmp = (*stack_a);
	while (tmp != NULL)
	{
		if (next_num > tmp->num)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	is_current_biggest(t_node **stack_a, int next_num)
{
	t_node	*tmp;

	if (*stack_a == NULL && (*stack_a)->next != NULL)
		return (0);
	tmp = (*stack_a);
	while (tmp != NULL)
	{
		if (next_num < tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_stack_of_3(t_node **stack_a, t_data **data)
{
	int	current;
	int	next;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	get_first_two_values(stack_a, &current, &next);
	while ((*data)->size-- > 1 && !is_sorted(*stack_a))
	{
		if (current > next)
		{
			if (is_current_biggest(stack_a, current))
				ft_rotate(stack_a, "ra");
			else
				ft_swap(stack_a, "sa");
			get_first_two_values(stack_a, &current, &next);
			continue ;
		}
		if (get_smaller_num_count(stack_a, current) == 0)
			ft_swap(stack_a, "sa");
		else
			ft_rotate(stack_a, "ra");
		get_first_two_values(stack_a, &current, &next);
	}
}

void	sort_stack_of_5(t_node **stack_a, t_node **stack_b, t_data **data)
{
	int	current;
	int	next;
	int	pushed;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	pushed = 0;
	get_first_two_values(stack_a, &current, &next);
	while (pushed < 2)
	{
		if (get_smaller_num_count(stack_a, current) == 0
			|| (pushed == 0 && get_smaller_num_count(stack_a, current) <= 1))
		{
			ft_push(stack_a, stack_b, "pb");
			pushed++;
		}
		else
			ft_rotate(stack_a, "ra");
		get_first_two_values(stack_a, &current, &next);
	}
	sort_stack_of_3(stack_a, data);
	if (pushed == 2 && get_smaller_num_count(stack_b, (*stack_b)->num) == 0)
		ft_swap(stack_b, "sb");
	while ((*stack_b) != NULL)
		ft_push(stack_b, stack_a, "pa");
}

int	sort_small_stack(t_node **stack_a, t_node **stack_b, t_data **data)
{
	if ((*data)->size == 3)
		sort_stack_of_3(stack_a, data);
	else if ((*data)->size == 5)
		sort_stack_of_5(stack_a, stack_b, data);
	else
		sort_big_stack(stack_a, stack_b, data);
	stack_b = NULL;
	return (1);
}

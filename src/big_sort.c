/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:48:07 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 22:47:58 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	merge_merged(t_node **stack_a, t_node **stack_b, t_data **data)
{
	int	i;

	i = 0;
	while (i++ < (*data)->breakpoint && *stack_a)
	{
		set_top_desc(stack_b, (*stack_a)->num, data);
		ft_push(stack_a, stack_b, "pb");
	}
	route_til_index_on_top(stack_b, get_index_of_max(stack_b), data);
}

void	final_merge(t_node **stack_a, t_node **stack_b, t_data **data)
{
	(*data)->reverse = "rra";
	(*data)->rotate = "ra";
	while ((*stack_b) != NULL)
	{
		set_top_asc(stack_a, (*stack_b)->num, data);
		ft_push(stack_b, stack_a, "pa");
	}
	route_til_index_on_top(stack_a, get_index_of_min(stack_a), data);
}

int	sort_big_stack(t_node **stack_a, t_node **stack_b, t_data **data)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	merge_sort(stack_a, stack_b, data);
	merge_merged(stack_a, stack_b, data);
	final_merge(stack_a, stack_b, data);
	return (1);
}

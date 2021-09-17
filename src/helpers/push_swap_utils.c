/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:57:25 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 22:48:57 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	get_first_two_values(t_node **stack, int *current, int *next)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*current = (*stack)->num;
	*next = (*stack)->next->num;
}

int	is_sorted(t_node *stack)
{
	int		num;
	t_node	*tmp;

	if (stack == NULL || stack->next == NULL)
		return (1);
	tmp = stack;
	while (tmp->next != NULL)
	{
		num = tmp->num;
		tmp = tmp->next;
		if (num > tmp->num)
			return (0);
		num = tmp->num;
	}
	return (1);
}

int	get_index_of_min(t_node **stack)
{
	t_node	*tmp;
	int		min;
	int		num;
	int		i;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	num = (*stack)->num;
	min = 0;
	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (num > tmp->num)
		{
			num = tmp->num;
			min = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min);
}

int	get_index_of_max(t_node **stack)
{
	t_node	*tmp;
	int		max;
	int		num;
	int		i;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	num = (*stack)->num;
	max = 0;
	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (num < tmp->num)
		{
			num = tmp->num;
			max = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max);
}

int	get_value_by_index(t_node **stack, int index)
{
	t_node	*tmp;
	int		value;

	if (*stack == NULL)
		return (0);
	tmp = *stack;
	while (tmp != NULL && index-- >= 0)
	{
		value = tmp->num;
		tmp = tmp->next;
	}
	return (value);
}

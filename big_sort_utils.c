/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:57:17 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 18:11:51 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	reverse_stack_n_times(t_node **stack_b, int index, char *operation)
{
	if (*stack_b == NULL)
		return ;
	while (index-- > 0)
		ft_reverse(stack_b, operation);
}

int	rotate_stack_n_times(t_node **stack_b, int index, char *operation)
{
	if (*stack_b == NULL)
		return (0);
	while (index-- > 0)
		ft_rotate(stack_b, operation);
	return (0);
}

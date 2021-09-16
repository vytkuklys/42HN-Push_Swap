/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:57:25 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 18:05:03 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	get_first_two_values(t_node **stack, int *current, int *next)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*current = (*stack)->num;
	*next = (*stack)->next->num;
}

int	get_first_value(t_node **stack)
{
	int	value;

	if (*stack == NULL)
		return (0);
	value = (*stack)->num;
	return (value);
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

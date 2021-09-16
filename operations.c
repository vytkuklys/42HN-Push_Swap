/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:06:53 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 18:00:31 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rotate(t_node **stack, char *operation)
{
	t_node	*head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = (*stack);
	*stack = (*stack)->next;
	ft_lstadd_back(stack, head);
	head->next = NULL;
	write(1, operation, 2);
	write(1, "\n", 1);
}

void	ft_reverse(t_node **stack, char *operation)
{
	t_node	*second_last;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	ft_lstadd_front(stack, last);
	second_last->next = NULL;
	if (operation)
	{
		write(1, operation, 3);
		write(1, "\n", 1);
	}
}

void	ft_push(t_node **stack_from, t_node **stack_to, char *operation)
{
	t_node	*top;

	if (*stack_from == NULL)
		return ;
	top = *stack_from;
	if ((*stack_from)->next == NULL)
		*stack_from = NULL;
	else
		*stack_from = (*stack_from)->next;
	top->next = NULL;
	ft_lstadd_front(stack_to, top);
	if (operation)
	{
		write(1, operation, 2);
		write(1, "\n", 1);
	}
}

void	ft_swap(t_node **stack, char *operation)
{
	t_node	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	ft_lstadd_front(stack, second);
	if (operation)
	{
		write(1, operation, 2);
		write(1, "\n", 1);
	}
}

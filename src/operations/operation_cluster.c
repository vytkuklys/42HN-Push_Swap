/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_cluster.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:58:53 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 22:49:27 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

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

void	push_stack_n_times(t_node **src, t_node **dest, int n, char *operation)
{
	t_node	*current;

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

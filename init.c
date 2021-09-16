/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:04:51 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 18:05:17 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_merge_size(int size)
{
	if (size >= 500)
		return (size / 10);
	else if (size >= 25)
		return (size / 4);
	else
		return (size);
}

int	get_breakpoint(int size, int merge_size)
{
	if (size >= 25)
		return (size - (2 * merge_size));
	else
		return (size);
}

void	initialise(t_data **data, t_node **stack_a)
{
	(*data)->reverse = "rrb";
	(*data)->rotate = "rb";
	(*data)->size = ft_lstsize(*stack_a);
	(*data)->merge_size = get_merge_size((*data)->size);
	(*data)->breakpoint = get_breakpoint((*data)->size, (*data)->merge_size);
}

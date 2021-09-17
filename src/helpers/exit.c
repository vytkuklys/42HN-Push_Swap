/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:50:41 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/17 20:59:26 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	free_structs_exit(t_data **data, t_node **stack, int failure)
{
	free(*data);
	ft_lstclear(stack);
	if (failure)
	{
		ft_putstr_fd("Error", 1);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

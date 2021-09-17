/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:42:20 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/17 21:01:32 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int argv, char *argc[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_data	*data;

	if (argv <= 1)
		return (0);
	if (are_args_valid(&argc[1], argv - 1))
		return (ft_putstr_fd("Error", 1));
	stack_b = NULL;
	stack_a = build_stack(&argc[1], argv - 1);
	data = (t_data *)malloc(sizeof(t_data));
	if (stack_a == NULL || data == NULL)
		free_structs_exit(&data, &stack_a, 1);
	if (is_sorted(stack_a))
		free_structs_exit(&data, &stack_a, 0);
	initialise(&data, &stack_a);
	sort_stack(&stack_a, &stack_b, &data);
	ft_lstclear(&stack_a);
	free(data);
	if (is_stack_b_invalid(&stack_b))
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

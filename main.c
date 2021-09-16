/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:42:20 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 18:04:48 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	add_split_numbers_to_stack(t_node **stack_a, char *str)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_split(str, ' ');
	if (nums[0] == NULL)
		return (1);
	while (nums[i] != NULL)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(nums[i])));
		i++;
	}
	ft_free_2d_array(&nums, i - 1);
	return (0);
}

t_node	*build_stack(char **argc, int len)
{
	int		i;
	t_node	*stack_a;

	stack_a = NULL;
	i = 0;
	while (i < len)
	{
		if (ft_strchr(argc[i], ' '))
		{
			if (add_split_numbers_to_stack(&stack_a, argc[i]))
				return (ft_lstclear(&stack_a));
		}
		else
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argc[i])));
		i++;
	}
	return (stack_a);
}

int	main(int argv, char *argc[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_data	*data;

	if (argv <= 1 || are_args_valid(&argc[1], argv - 1))
		return (ft_putstr_fd("Error", 1));
	stack_b = NULL;
	stack_a = build_stack(&argc[1], argv - 1);
	data = (t_data *)malloc(sizeof(t_data));
	if (stack_a == NULL || data == NULL)
		return (ft_putstr_fd("Error", 1));
	if (is_sorted(stack_a))
		return (0);
	initialise(&data, &stack_a);
	if (data->size <= 5)
		sort_small_stack(&stack_a, &stack_b, &data);
	else
		sort_big_stack(&stack_a, &stack_b, &data);
	ft_lstprint(stack_a);
	ft_lstclear(&stack_a);
	free(data);
	return (0);
}

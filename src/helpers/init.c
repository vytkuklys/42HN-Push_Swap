/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:04:51 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/17 20:58:02 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	get_merge_size(int size)
{
	if (size >= 250)
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
	(*data)->rotate_nr = 0;
	(*data)->reverse_nr = 0;
	(*data)->size = ft_lstsize(*stack_a);
	(*data)->merge_size = get_merge_size((*data)->size);
	(*data)->breakpoint = get_breakpoint((*data)->size, (*data)->merge_size);
}

int	add_split_numbers_to_stack(t_node **stack_a, char *str)
{
	int			i;
	char		**nums;
	long long	num;

	i = 0;
	nums = ft_split(str, ' ');
	if (nums[0] == NULL)
		return (1);
	while (nums[i] != NULL)
	{
		num = (long long)ft_atoi(nums[i]);
		if (!is_num_int(num) || has_list_duplicates(stack_a, (int)num))
		{
			while (nums[i] != NULL)
				i++;
			ft_free_2d_array(&nums, i - 1);
			return (1);
		}
		ft_lstadd_back(stack_a, ft_lstnew((int)num));
		i++;
	}
	ft_free_2d_array(&nums, i - 1);
	return (0);
}

t_node	*build_stack(char **argc, int len)
{
	int			i;
	t_node		*stack_a;
	long long	num;

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
		{
			num = (long long)ft_atoi(argc[i]);
			if (!is_num_int(num) || has_list_duplicates(&stack_a, (int)num))
				return (ft_lstclear(&stack_a));
			ft_lstadd_back(&stack_a, ft_lstnew((int)num));
		}
		i++;
	}
	return (stack_a);
}

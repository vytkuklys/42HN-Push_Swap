/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:42:20 by vkuklys           #+#    #+#             */
/*   Updated: 2021/08/28 20:06:17 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void initialise(t_data **data)
{
	(*data)->reverse = 0;
	(*data)->rotate = 0;
	(*data)->size = 0;
	(*data)->op = 0;
}

t_node *build_stack(char **args, int len)
{
	int i;
	t_node *stack_a;

	stack_a = ft_lstnew(ft_atoi(args[0]));
	if (stack_a == NULL)
		return NULL;
	i = 1;
	while (i < len)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(args[i])));
		i++;
	}
	return stack_a;
}

int are_args_valid(char **argc, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		if (argc[i][j] == '\0')
			return 1;
		while (argc[i][j] != '\0')
		{
			if (!(argc[i][j] - 48 >= 0 && argc[i][j] - 48 <= 9))
				if(!(j == 0 && argc[i][j] == '-' && argc[i][j + 1] != '\0'))
					return 1;
			j++;
		}
		i++;
	}
	return 0;
}

void ft_rotate(t_node **stack, char *operation)
{
	t_node *head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = (*stack);
	*stack = (*stack)->next;
	ft_lstadd_back(stack, head);
	head->next = NULL;
	write(1, operation, 2);
	write(1, "\n", 1);
}

void ft_reverse(t_node **stack)
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
}

int is_sorted(t_node *stack)
{
	int num;
	t_node *tmp;

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

void ft_push(t_node **stack_from, t_node **stack_to, char *operation)
{
	t_node *top;

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

void ft_swap(t_node **stack, char *operation)
{
	t_node *second;

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

int get_min(int a, int b)
{
	return (a < b);
}

int get_index_of_smaller_num(t_node **stack_b, int next_num)
{
	t_node *tmp;
	int index;

	if (*stack_b == NULL)
		return 0;
	index = 0;
	tmp = *stack_b;
	while (tmp->next != NULL)
	{
		if (tmp->num < next_num)
			return index;
		tmp = tmp->next;
		index++;
	}
	if (tmp->num < next_num)
		return index;
	return -1;
}

int get_index_of_bigger_num(t_node **stack_a, int next_num)
{
	t_node *tmp;
	int index;

	if (*stack_a == NULL && (*stack_a)->next != NULL)
		return (0);
	index = 0;
	tmp = (*stack_a)->next;
	while (tmp->next != NULL && tmp->num < next_num)
	{
		tmp = tmp->next;
		index++;
		// write(1, ">", 1);
		// ft_putnbr_fd(index, 1);
		// write(1, "<", 1);

	}
	if (tmp->num < next_num)
		index++;
	return index;
}

int prepare_stack_b(t_node **stack_b, int next_num, t_data **data)
{
	int index;
	int i;

	i = 0;
	index = get_index_of_smaller_num(stack_b, next_num);
	while (index - i++ > 0)
	{
		ft_rotate(stack_b, "rb");
		(*data)->op++;
	}
	if (index > 0)
		(*data)->reverse = index;
	else if (index == -1)
		(*data)->rotate = 1;
	return 0;
}

void adjust_stack_b(t_node **stack_b, t_data **data)
{
	while ((*data)->reverse != 0)
	{
		ft_reverse(stack_b);
		write(1, "rrb\n", 4);
		(*data)->reverse--;
		(*data)->op++;
	}
	if ((*data)->rotate)
	{
		ft_rotate(stack_b, "rb");
		(*data)->rotate = 0;
		(*data)->op++;
	}
}

int sort_big_stack(t_node **stack_a, t_node **stack_b, t_data **data)
{
	t_node *current;
	t_node *next;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	current = *stack_a;
	next = (*stack_a)->next;
	while ((*data)->size-- > 1)
	{
		if (get_min(current->num, next->num))
		{
			prepare_stack_b(stack_b, current->num, data);
			current = next;
			next = next->next;
		}
		else
		{
			prepare_stack_b(stack_b, next->num, data);
			next=next->next;
			ft_swap(stack_a, "sa");
			(*data)->op++;
		}
		ft_push(stack_a, stack_b, "pb");
		(*data)->op++;
		adjust_stack_b(stack_b, data);
	}
	ft_lstprint(*stack_b);
	return (1);
}

void fill_stack_a(t_node **stack_a, t_node **stack_b, t_data **data)
{
	t_node *current;

	if (*stack_b == NULL)
		return ;
	current = (*stack_b)->next;
	while (current != NULL)
	{
		ft_push(stack_b, stack_a, "pa");
		(*data)->op++;
		*stack_b = current;
		current = current->next;
	}
	ft_push(stack_b, stack_a, "pa");
	(*data)->op++;
}



int sort_small_stack(t_node **stack_a, t_node **stack_b, t_data **data)
{
	t_node *current;
	t_node *next;
	int 	bigger_pos;
	int		flag;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (0);
	current = *stack_a;
	next = (*stack_a)->next;
	while ((*data)->size-- > 1)
	{
		bigger_pos = get_index_of_bigger_num(stack_a, current->num);
		write(1, "---", 1);
		ft_putnbr_fd(bigger_pos, 1);
		write(1, "\n", 1);
		if (bigger_pos > 1)
		{
			current = next;
			next = next->next;
			ft_rotate(stack_a, "ra");
			(*data)->op++;
		}
		if (get_min(current->num, next->num))
		{
			prepare_stack_b(stack_b, current->num, data);
			flag = current->num;
			current = next;
			next = next->next;
		}
		else
		{
			prepare_stack_b(stack_b, next->num, data);
			flag = next->num;
			next=next->next;
			ft_swap(stack_a, "sa");
				(*data)->op++;
		}
		// ft_putnbr_fd(get_index_of_bigger_num(stack_b, flag), 1);
		if ((*data)->size > 1 || ((*data)->size == 1 && !get_index_of_bigger_num(stack_b, flag)))
		{
			// if ((*data)->size > 1)
			// {
				// printf("%d", get_index_of_bigger_num(stack_b, flag));
				ft_push(stack_a, stack_b, "pb");
				(*data)->op++;

			}
		// }

		adjust_stack_b(stack_b, data);
		ft_lstprint(*stack_a);
		write(1, "---a\n", 5);
		ft_lstprint(*stack_b);
		write(1, "---b\n", 5);
	}
	fill_stack_a(stack_a, stack_b, data);
	printf("\noperations: %d\n", (*data)->op);
	ft_lstprint(*stack_a);

	return (1);
}

int main(int argv, char *argc[])
{
	t_node *stack_a;
	t_node *stack_b;
	t_data *data;

	if (argv <= 1 || are_args_valid(&argc[1], argv - 1))
		return (0);
	stack_b = NULL;
	stack_a = build_stack(&argc[1], argv - 1);
	ft_lstprint(stack_a);
	write(1, "\n", 1);
	data = (t_data *)malloc(sizeof(t_data));
	initialise(&data);
	if (stack_a == NULL || data == NULL || is_sorted(stack_a))
		return (0);
	data->size = ft_lstsize(stack_a);
	if (data->size < 10)
		sort_small_stack(&stack_a, &stack_b, &data);
	else
		sort_big_stack(&stack_a, &stack_b, &data);
	return (0);
}

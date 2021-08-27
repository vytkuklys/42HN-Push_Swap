#include "pushswap.h"

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
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

void ft_rotate(t_node **stack)
{
	t_node *head;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	head = (*stack);
	*stack = (*stack)->next;
	ft_lstadd_back(stack, head);
	head->next = NULL;
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
	tmp = stack->next;
	num = stack->num;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (num > tmp->num)
			return (0);
		num = tmp->num;
	}
	return (1);
}

void ft_push(t_node **stack_from, t_node **stack_to)
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
}

void ft_swap(t_node **stack)
{
	t_node *second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	ft_lstadd_front(stack, second);
}

int get_min(int a, int b)
{
	return (a < b);
}

int sort_stack(t_node **stack_a, t_node **stack_b)
{
	int len;
	t_node *current;
	t_node *next;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return 0;
	current = *stack_a;
	next = (*stack_a)->next;
	len = ft_lstsize(*stack_a);
	while (len-- > 0)
	{
		if (len == 0)
		{
			ft_push(stack_a, stack_b);
			break ;
		}
		printf("%d - %d\n", current->num, next->num);
		if (get_min(current->num, next->num))
		{
			current = next;
			next = next->next;
			prepare_stack_b(stack_b);
			ft_push(stack_a, stack_b);
		}
		else
		{
			next=next->next;
			ft_swap(stack_a);
			ft_push(stack_a, stack_b);
		}
	}
	ft_lstprint(*stack_b);
	write(1, "b\na", 3);
	ft_lstprint(*stack_a);
	return 1;
}

int main(int argv, char *argc[])
{
	t_node *stack_a;
	t_node *stack_b;

	if (argv <= 1 || are_args_valid(&argc[1], argv - 1))
		return (0);
	stack_b = NULL;
	stack_a = build_stack(&argc[1], argv - 1);
	if (stack_a == NULL)
		return (0);
	if (is_sorted(stack_a))
		return (0);
	sort_stack(&stack_a, &stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:11:40 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/17 21:07:13 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "../libft/libft.h"

void	ft_rotate(t_node **stack, char *operation);
void	ft_reverse(t_node **stack, char *operation);
void	ft_push(t_node **stack_from, t_node **stack_to, char *operation);
void	ft_swap(t_node **stack, char *operation);
void	push_stack_n_times(t_node **src, t_node **dest, int n, char *operation);
int		rotate_stack_n_times(t_node **stack_b, int index, char *operation);
void	reverse_stack_n_times(t_node **stack_b, int index, char *operation);
int		are_args_valid(char **argc, int len);
int		is_stack_b_invalid(t_node **stack_b);
int		is_sorted(t_node *stack);
int		is_num_int(long long num);
int		has_list_duplicates(t_node **stack_a, int num);
int		get_index_of_min(t_node **stack_a);
int		get_index_of_max(t_node **stack_a);
int		get_value_by_index(t_node **stack_a, int index);
int		get_first_value(t_node **stack_a);
int		get_reversal_count_desc(t_node **stack_b, int next_num);
int		get_rotation_count_desc(t_node **stack_b, int next_num);
int		get_reversal_count_asc(t_node **stack_b, int next_num);
int		get_rotation_count_asc(t_node **stack_b, int next_num);
void	get_first_two_values(t_node **stack_a, int *current, int *next);
int		sort_stack(t_node **stack_a, t_node **stack_b, t_data **data);
int		sort_big_stack(t_node **stack_a, t_node **stack_b, t_data **data);
void	initialise(t_data **data, t_node **stack_a);
void	merge_sort(t_node **stack_a, t_node **stack_b, t_data **data);
int		route_til_index_on_top(t_node **stack_b, int index, t_data **data);
int		set_top_desc(t_node **stack, int next_num, t_data **data);
int		set_top_asc(t_node **stack, int next_num, t_data **data);
t_node	*build_stack(char **argc, int len);
int		add_split_numbers_to_stack(t_node **stack_a, char *str);
int		free_structs_exit(t_data **data, t_node **stack, int failure);

#endif
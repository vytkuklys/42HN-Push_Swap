/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:18 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/16 18:09:27 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	are_args_valid(char **argc, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		if (argc[i][j] == '\0')
			return (1);
		while (argc[i][j] != '\0')
		{
			if (argc[i][j] == '-' && argc[i][j + 1] != '\0'
				&& (is_digit(argc[i][j])))
			{
				j++;
				continue ;
			}
			if (!(is_digit(argc[i][j])) && argc[i][j] != ' ')
				if (!(j == 0 && argc[i][j] == '-' && argc[i][j + 1] != '\0'))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

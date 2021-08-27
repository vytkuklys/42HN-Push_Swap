/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:08:17 by vkuklys           #+#    #+#             */
/*   Updated: 2021/07/16 21:44:31 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstdelone(t_node *lst, int (*del)(void *))
{
	if (!lst || (*del) == NULL)
		return ;
	(*del)(lst->next);
	free(lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:29:36 by vkuklys           #+#    #+#             */
/*   Updated: 2021/07/22 15:46:26 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_toupper(int arg)
{
	if (arg >= 97 && arg <= 122)
		return (arg - 32);
	return (arg);
}

int main(void)
{
	ft_toupper('a');
	return 0;
}
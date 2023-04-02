/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:19:02 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 19:50:27 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **a, int size, t_listopt **result, t_all *all)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (a == NULL || *a == 0)
		return ;
	while (ft_checksorted(*a, size) != 1)
	{
		tmp = (*a)->next;
		tmp2 = tmp->next;
		if (ft_checksorted_d(*a, size))
			ft_rotate_a(a, result, all);
		else if ((*a)->content > tmp2->content)
			ft_rotate_a(a, result, all);
		else if ((*a)->content > tmp->content)
			ft_swap_a(a, result, all);
		else
			ft_rotate_a(a, result, all);
	}
}

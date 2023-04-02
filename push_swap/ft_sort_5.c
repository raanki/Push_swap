/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:40:32 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 19:31:06 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_m(t_list *l, int choice)
{
	int	min;
	int	max;

	if (l == NULL)
		return (0);
	min = l->content;
	max = l->content;
	while (ft_lstsize(l))
	{
		if (min > l->content)
			min = l->content;
		if (max < l->content)
			max = l->content;
		l = l->next;
	}
	if (choice == 1)
		return (min);
	else
		return (max);
}

void	ft_sort_5(t_list **a, t_list **b, t_listopt **result, t_all **all)
{
	int	min;
	int	max;

	min = ft_get_m(*a, 1);
	max = ft_get_m(*a, 0);
	while (ft_lstsize(*b) != 2)
		if ((*a)->content == min || (*a)->content == max)
			ft_push_b(a, b, result, *all);
	else
		ft_rotate_a(a, result, *all);
	ft_sort_3(a, 3, result, *all);
	while (ft_lstsize(*b))
	{
		if ((*b)->content == max)
		{
			ft_push_a(a, b, result, *all);
			ft_rotate_a(a, result, *all);
		}
		else if ((*b)->content == min)
			ft_push_a(a, b, result, *all);
	}
}

void	ft_sort_4(t_list **a, t_list **b, t_listopt **result, t_all **all)
{
	int	min;
	int	max;

	min = ft_get_m(*a, 1);
	max = ft_get_m(*a, 0);
	while (ft_lstsize(*b) != 1)
		if ((*a)->content == min || (*a)->content == max)
			ft_push_b(a, b, result, *all);
	else
		ft_rotate_a(a, result, *all);
	ft_sort_3(a, 3, result, *all);
	while (ft_lstsize(*b))
	{
		if ((*b)->content == max)
		{
			ft_push_a(a, b, result, *all);
			ft_rotate_a(a, result, *all);
		}
		else if ((*b)->content == min)
			ft_push_a(a, b, result, *all);
	}
}

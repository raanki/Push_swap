/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:38:03 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 19:46:17 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_findlst_value(t_all *all, int value)
{
	t_list	*tmp;

	tmp = all->b;
	while (tmp != NULL && tmp->content != value)
		tmp = tmp->next;
	return (tmp);
}

void	ft_topmin(t_all *all)
{
	t_list	*tmp;
	int		i;
	int		moov;

	i = 0;
	if (all->b == NULL || ft_lstsize(all->b) == 1)
		return ;
	tmp = ft_findlst_value(all, ft_get_m(all->b, 0));
	if (ft_calcpos_top(all, tmp, all->b) + 1
		> ft_calcpos_bottom(all, tmp, all->b))
	{
		moov = ft_calcpos_bottom(all, tmp, all->b);
		while (i++ < moov)
			ft_rrotate_b(&(all->b), &(all->result), all);
	}
	else
	{
		moov = ft_calcpos_top(all, tmp, all->b);
		while (i++ < moov)
			ft_rotate_b(&(all->b), &(all->result), all);
	}
}

void	ft_placeinb(t_all *all)
{
	if (all->a->content < all->b->content)
		ft_rotate_a(&(all->a), &(all->result), all);
}

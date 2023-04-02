/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:21:07 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 19:28:44 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_go_topa(t_all **all, t_list *first, t_list *second)
{
	int	i;
	int	moov;

	i = 0;
	if (ft_calcpos_top(*all, first, (*all)->a)
		> ft_calcpos_bottom((*all), second, (*all)->a))
	{
		moov = ft_calcpos_bottom((*all), second, (*all)->a);
		while (i++ < moov)
			ft_rrotate_a(&((*all)->a), &((*all)->result), *all);
	}
	else
	{
		moov = ft_calcpos_top((*all), first, (*all)->a);
		while (i++ < moov)
			ft_rotate_a(&((*all)->a), &((*all)->result), *all);
	}
	ft_topmin(*all);
	ft_push_b(&((*all)->a), &((*all)->b), &((*all)->result), *all);
}

void	ft_topmax(t_all *all)
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

void	ft_bigsort(t_all **all)
{
	int		chunk_aim;
	t_list	*first;
	t_list	*second;
	int		i;

	chunk_aim = 1;
	i = 0;
	while ((*all)->a != NULL && chunk_aim < (*all)->nb_chunk + 1)
	{
		if (i == (*all)->size_chunk)
		{
			chunk_aim++;
			i = 0;
		}
		first = ft_hold_first(*all, chunk_aim);
		second = ft_hold_second(*all, chunk_aim);
		ft_go_topa(all, first, second);
		i++;
	}
	if ((*all)->a != NULL)
		while ((*all)->a != NULL)
			ft_push_b(&((*all)->a), &((*all)->b), &((*all)->result), *all);
	ft_bigsort_return(all);
}

void	ft_bigsort_return(t_all **all)
{
	while ((*all)->b != NULL)
	{
		ft_topmax(*all);
		ft_push_a(&((*all)->a), &((*all)->b), &((*all)->result), *all);
	}
}

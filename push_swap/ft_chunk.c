/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:48:56 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 19:38:00 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_numbchunk(t_all *all, int chunk_aim, t_list *current)
{
	int		start;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = all->insert;
	start = (chunk_aim - 1) * all->size_chunk;
	while (i++ < start && tmp != NULL)
		tmp = tmp->next;
	while (tmp != NULL && i++ < (start + all->size_chunk) + 1)
	{
		if (tmp->content == current->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_list	*ft_hold_first(t_all *all, int chunk_aim)
{
	t_list	*tmp;

	tmp = all->a;
	while (tmp != NULL && ft_check_numbchunk(all, chunk_aim, tmp) == 0)
		tmp = tmp->next;
	return (tmp);
}

int	ft_calcpos_top(t_all *all, t_list *lst, t_list *ab)
{
	int		i;
	t_list	*tmp;

	(void)all;
	tmp = ab;
	i = 0;
	while (tmp != NULL && tmp != lst)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_calcpos_bottom(t_all *all, t_list *lst, t_list *ab)
{
	int		i;

	(void)all;
	(void)ab;
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_hold_second(t_all *all, int chunk_aim)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = all->size_lst;
	while (i != 0)
	{
		tmp = all->a;
		j = 0;
		while (tmp->next != NULL && j++ != i)
			tmp = tmp->next;
		if (ft_check_numbchunk(all, chunk_aim, tmp) == 1)
			return (tmp);
		i--;
	}
	return (NULL);
}

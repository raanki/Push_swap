/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:38:55 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 18:42:18 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksorted(t_list *lst, int size)
{
	t_list	*tmp;
	t_list	*prec;
	int		i;

	i = 0;
	if (lst == NULL || lst->next == NULL)
		return (1);
	tmp = lst->next;
	prec = lst;
	while (tmp != NULL && i < size)
	{
		if ((lst->content == 2147483647 && lst->next != NULL)
			|| prec->content + 1 > tmp->content)
			return (0);
		tmp = tmp->next;
		prec = prec->next;
		i++;
	}
	return (1);
}

int	ft_checksorted_d(t_list *lst, int size)
{
	t_list	*tmp;
	t_list	*prec;
	int		i;

	i = 0;
	if (lst == NULL || lst->next == NULL)
		return (1);
	tmp = lst->next;
	prec = lst;
	while (tmp != NULL && i < size)
	{
		if (prec->content < tmp->content)
			return (0);
		tmp = tmp->next;
		prec = prec->next;
		i++;
	}
	return (1);
}

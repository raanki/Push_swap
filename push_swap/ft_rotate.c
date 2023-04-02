/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:39:27 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 19:41:34 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **lst, t_listopt **result, t_all *all)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstadd_back(lst, tmp);
	tmp->next = NULL;
	add_move(result, "ra", all);
}

void	ft_rotate_b(t_list **lst, t_listopt **result, t_all *all)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstadd_back(lst, tmp);
	tmp->next = NULL;
	add_move(result, "rb", all);
}

void	ft_rotate_rr(t_list **a, t_list **b, t_listopt **result, t_all *all)
{
	t_list	*tmp;

	if (*a == NULL || *b == NULL)
		return ;
	tmp = ft_lstnew((*a)->content, all);
	ft_lstadd_back(a, tmp);
	tmp->next = NULL;
	*a = (*a)->next;
	tmp = ft_lstnew((*b)->content, all);
	ft_lstadd_back(b, tmp);
	tmp->next = NULL;
	*b = (*b)->next;
	add_move(result, "rr", all);
}

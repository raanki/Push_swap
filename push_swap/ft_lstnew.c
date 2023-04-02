/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:40:52 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 21:30:02 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content, t_all *all)
{
	t_list	*l;

	l = malloc(sizeof(t_list));
	if (all == NULL)
	{
		free_all(all);
		ft_printf("Error() : can't malloc\n");
		exit(EXIT_FAILURE);
	}
	l->content = content;
	l->next = NULL;
	return (l);
}

t_listopt	*ft_lstnewstr(char *s, t_all *all)
{
	t_listopt	*l;

	l = malloc(sizeof(t_listopt));
	if (all == NULL)
	{
		free_all(all);
		ft_printf("Error() : can't malloc\n");
		exit(EXIT_FAILURE);
	}
	l->content = s;
	l->next = NULL;
	return (l);
}

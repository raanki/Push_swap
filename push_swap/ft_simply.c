/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:38:25 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 19:34:29 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsizechar(t_listopt *lst)
{
	if (lst == NULL)
		return (0);
	return (1 + ft_lstsizechar(lst->next));
}

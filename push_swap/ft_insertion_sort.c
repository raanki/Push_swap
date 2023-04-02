/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:10:51 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 19:48:51 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move(t_listopt **result, char *s, t_all *all)
{
	ft_lstadd_backchar(result, ft_lstnewstr(s, all));
}

void	ft_initvar(t_list **list, t_list **current, t_list **head)
{
	*list = NULL;
	*current = *head;
}

t_list	*ft_insertion_sort(t_list *head)
{
	t_list	*list;
	t_list	*current;
	t_list	*next_node;
	t_list	*prev;

	ft_initvar(&list, &current, &head);
	while (current != NULL)
	{
		next_node = current->next;
		if (list == NULL || current->content < list->content)
		{
			current->next = list;
			list = current;
		}
		else
		{
			prev = list;
			while (prev->next != NULL && prev->next->content < current->content)
				prev = prev->next;
			current->next = prev->next;
			prev->next = current;
		}
		current = next_node;
	}
	return (list);
}

t_list	*copy_list(t_list *head, t_all *all)
{
	t_list	*new_head;
	t_list	*current_node;
	t_list	*current_source;
	t_list	*new_node;

	new_head = malloc(sizeof(t_list));
	if (new_head == NULL)
	{
		free_all(all);
		ft_printf("Error() : can't malloc\n");
		exit(EXIT_FAILURE);
	}
	new_head->content = head->content;
	new_head->next = NULL;
	current_node = new_head;
	current_source = head->next;
	while (current_source != NULL)
	{
		new_node = ft_lstnew(current_source->content, all);
		current_node->next = new_node;
		current_node = current_node->next;
		current_source = current_source->next;
	}
	return (new_head);
}

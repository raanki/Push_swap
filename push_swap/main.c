/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:30:36 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 22:18:07 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlist(t_list *lst)
{
	if (lst == NULL)
		return ;
	ft_printf("%d ", lst->content);
	ft_printlist(lst->next);
}

void	ft_printlistchar(t_listopt *lst)
{
	if (lst == NULL)
		return ;
	ft_printf("%s\n", lst->content);
	ft_printlistchar(lst->next);
}

t_list	*ft_argtolist(int argc, char **argv, t_all *all)
{
	int		i;

	i = 1;
	all->a = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&(all->a), ft_lstnew(ft_atoi(argv[i]), all));
		i++;
	}
	return (all->a);
}

void	free_all(t_all *all)
{
	if (&(all->a) != NULL)
		ft_lstclear(&(all->a));
	if (&(all->b) != NULL)
		ft_lstclear(&(all->b));
	if (&(all->insert) != NULL)
		ft_lstclear(&(all->insert));
	if (&(all->result) != NULL)
		ft_lstclearchar(&(all->result));
	if (all != NULL)
		free(all);
}

int	main(int argc, char **argv)
{
	t_all			*all;

	if (argc != 1)
	{
		all = malloc(sizeof(t_all));
		if (all == NULL)
		{
			ft_printf("Error() : can't malloc\n");
			exit(EXIT_FAILURE);
		}
		ft_init_all(all, argc, argv);
		ft_init_sizechunk(all);
		check_all(argc, argv, &all);
		if (all->size_lst <= 3)
			ft_sort_3(&(all->a), 3, &(all->result), all);
		else if (all->size_lst == 5)
			ft_sort_5(&(all->a), &(all->b), &(all->result), &all);
		else if (all->size_lst == 4)
			ft_sort_4(&(all->a), &(all->b), &(all->result), &all);
		else
			ft_bigsort(&all);
		ft_printlistchar(all->result);
		free_all(all);
	}
	return (0);
}

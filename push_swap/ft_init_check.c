/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:21:06 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 20:57:00 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while ('\0' != argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')
						|| argv[i][j] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_init_all(t_all *all, int argc, char **argv)
{
	all->a = NULL;
	all->b = NULL;
	all->result = NULL;
	all->insert = NULL;
	if (argc == 2)
	{
		check_all(argc, argv, &all);
		free_all(all);
		exit(EXIT_SUCCESS);
	}
	all->a = ft_argtolist(argc, argv, all);
	all->insert = ft_insertion_sort(copy_list(all->a, all));
}

void	ft_init_sizechunk(t_all *all)
{
	all->size_lst = ft_lstsize(all->a);
	if (all->size_lst <= 100)
		all->nb_chunk = 6;
	else if (all->size_lst <= 200)
		all->nb_chunk = 8;
	else if (all->size_lst <= 300)
		all->nb_chunk = 9;
	else if (all->size_lst <= 400)
		all->nb_chunk = 10;
	else
		all->nb_chunk = 11;
	all->size_chunk = all->size_lst / all->nb_chunk;
}

int	check_double(t_list *lst)
{
	t_list	*tmp;
	t_list	*cure;

	cure = lst;
	while (cure != NULL)
	{
		tmp = cure->next;
		while (tmp != NULL)
		{
			if (cure->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		cure = cure->next;
	}
	return (0);
}

void	check_all(int argc, char **argv, t_all **all)
{
	if (check_arg(argc, argv) == 0
		|| ft_check_maxint(argc, argv, *all) == 0
		|| check_hyphen(argc, argv) == 0)
	{
		write (2, "Error\n", 6);
		free_all(*all);
		exit(EXIT_FAILURE);
	}
	if (ft_checksorted((*all)->a, ft_lstsize((*all)->a)))
	{
		free_all(*all);
		exit(EXIT_FAILURE);
	}
	if (check_double((*all)->a) == 1)
	{
		free_all(*all);
		write (2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

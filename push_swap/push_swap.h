/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <ranki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:33:59 by ranki             #+#    #+#             */
/*   Updated: 2023/03/15 20:53:10 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

# define _GREY "\033[30m"
# define _RED "\033[31m"
# define _GREEN "\033[32m"
# define _YELLOW "\033[33m"
# define _BLUE "\033[34m"
# define _PURPLE "\033[35m"
# define _CYAN "\033[36m"
# define _WHITE "\033[37m"
# define _END "\033[0m"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_listopt
{
	char				*content;
	struct s_listopt	*next;
}	t_listopt;

typedef struct s_all
{
	t_list		*a;
	t_list		*b;
	t_listopt	*result;
	int			size_chunk;
	int			nb_chunk;
	int			size_lst;
	t_list		*insert;
}	t_all;

char		*ft_itoa(int n);
int			ft_strcmp(const char *s1, const char *s2);
t_list		*ft_insertion_sort(t_list *head);
int			ft_check_numbchunk(t_all *all, int chunk_aim, t_list *current);
t_list		*ft_hold_first(t_all *all, int chunk_aim);
t_list		*ft_hold_second(t_all *all, int chunk_aim);
int			ft_calcpos_bottom(t_all *all, t_list *lst, t_list *ab);
int			ft_calcpos_top(t_all *all, t_list *lst, t_list *ab);
t_list		*copy_list(t_list *head, t_all *all);
t_list		*ft_lstnew(int content, t_all *all);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst);
int			ft_checksorted(t_list *lst, int size);
void		ft_swap_a(t_list **lst, t_listopt **result, t_all *all);
void		ft_swap_b(t_list **lst, t_listopt **result, t_all *all);
void		ft_swap_ss(t_list **a, t_list **b, t_listopt **result, t_all *all);
void		ft_push_a(t_list **a, t_list **b, t_listopt **result, t_all *all);
void		ft_push_b(t_list **a, t_list **b, t_listopt **result, t_all *all);
t_list		*ft_unstack(t_list **a);
void		ft_rotate_a(t_list **lst, t_listopt **result, t_all *all);
void		ft_rotate_b(t_list **lst, t_listopt **result, t_all *all);
void		ft_rrotate_a(t_list **a, t_listopt **result, t_all *all);
void		ft_rrotate_b(t_list **b, t_listopt **result, t_all *all);
void		ft_rrotate_rr(t_list **a, t_list **b,
				t_listopt **result, t_all *all);
int			ft_checksorted_d(t_list *lst, int size);
void		ft_sort_3(t_list **b, int size, t_listopt **result, t_all *all);
void		ft_lstadd_backchar(t_listopt **lst, t_listopt *new);
void		add_move(t_listopt **result, char *s, t_all *all);
t_listopt	*ft_lstnewstr(char *s, t_all *all);
t_listopt	*ft_lstlastchar(t_listopt *lst);
void		ft_lstclearchar(t_listopt **lst);
void		ft_printlistchar(t_listopt *lst);
void		ft_sort_5(t_list **a, t_list **b, t_listopt **result, t_all **all);
void		ft_printlist(t_list *lst);
void		ft_topmin(t_all *all);
void		ft_placeinb(t_all *all);
t_list		*ft_findlst_value(t_all *all, int value);
int			ft_get_m(t_list *l, int choice);
void		ft_bigsort(t_all **all);
void		ft_bigsort_return(t_all **all);
void		ft_init_all(t_all *all, int argc, char **argv);
void		ft_init_sizechunk(t_all *all);
int			check_arg(int argc, char **argv);
t_list		*ft_argtolist(int argc, char **argv, t_all *all);
int			check_double(t_list *lst);
void		check_all(int argc, char **argv, t_all **lst);
void		free_all(t_all *all);
int			ft_atoi(char *str);
char		*ft_strdup(const char *src);
size_t		ft_strlen(const char *d);
int			ft_check_maxint(int argc, char **argv, t_all *all);
void		ft_sort_4(t_list **a, t_list **b, t_listopt **result, t_all **all);
int			check_hyphen(int argc, char **argv);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:01:30 by ranki             #+#    #+#             */
/*   Updated: 2023/03/16 15:08:53 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	num;

	num = nb;
	if (num < 0)
	{
		num *= -1;
		ft_putchar('-');
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
	}
	ft_putchar(num % 10 + 48);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	num;
	int	i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int	ft_check_maxint(int argc, char **argv, t_all *all)
{
	int		i;
	char	*s;

	i = 1;
	while (i < argc)
	{
		s = ft_itoa(ft_atoi(argv[i]));
		if (ft_strcmp(s, argv[i]) != 0)
		{
			free_all(all);
			write(2, "Error\n", 6);
			free(s);
			exit(EXIT_FAILURE);
		}
		free(s);
		i++;
	}
	return (1);
}

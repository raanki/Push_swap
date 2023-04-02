/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:40:30 by ranki             #+#    #+#             */
/*   Updated: 2023/03/16 17:40:43 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		stop;

	stop = 0;
	len = ft_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = malloc(sizeof(char) * (ft_size(n) + 1));
	if (s == NULL)
		return (s);
	if (n < 0)
	{
		s[stop++] = '-';
		n *= -1;
	}
	s[len] = '\0';
	while (stop < len)
	{
		s[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}

char	*ft_strdup(const char *src)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cpy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	check_hyphen(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (argv[i][j] == '-')
			{
				if (argv[i][j + 1] == 0)
					return (0);
				else if (argv[i][j + 1] < '0' && argv[i][j + 1] > '9')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

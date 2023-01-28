/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:06:36 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/28 14:24:36 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isspace(const char *str)
{
	if (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	stock;
	long	sign;

	i = 0;
	stock = 0;
	sign = 1;
	while (ft_isspace(&str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		stock *= 10;
		stock += (str[i] - 48);
		i++;
	}
	return ((stock * sign));
}

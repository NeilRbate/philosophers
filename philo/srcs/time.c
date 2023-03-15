/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:10:19 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/15 13:13:41 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_usleep(long time, t_philo *philo)
{
	long long	start;
	long long	end;

	start = ft_gettime(philo);
	end = start + time;
	usleep(time * 1000 * 70 / 100);
	while (end - start > 0)
	{
		usleep(100);
		start = ft_gettime(philo);
	}
	return (0);
}

long long	ft_gettime(t_philo *philo)
{
	struct timeval	time;
	long long		ret;
	long long		t;

	gettimeofday(&time, NULL);
	usleep(50);
	t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	ret = (philo->time.tv_sec * 1000) + (philo->time.tv_usec / 1000);
	return (t - ret);
}

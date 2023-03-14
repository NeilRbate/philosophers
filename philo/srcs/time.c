/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:10:19 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/14 08:59:26 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	ft_gettime(t_philo *philo)
{
	struct timeval	time;
	long long		ret;

	gettimeofday(&time, NULL);
	ret = ((time.tv_sec * 1000) + (time.tv_usec / 1000))
		- ((philo->time.tv_sec * 1000) + (philo->time.tv_usec / 1000));
	return (ret);
}

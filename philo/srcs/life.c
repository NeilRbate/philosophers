/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:32:41 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/15 10:03:14 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print_fork(philo);
	pthread_mutex_lock(philo->right_fork);
	ft_print_eating(philo);
	philo->last_meal = ft_gettime(philo);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	ft_thinking(t_philo *philo)
{
	ft_print_thinking(philo);
	usleep(50);
	return (0);
}

int	ft_sleeping(t_philo *philo)
{
	ft_print_sleeping(philo);
	ft_usleep(philo->time_to_sleep, philo);
	return (0);
}

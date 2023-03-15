/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:32:41 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/15 13:18:53 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print_fork(philo);
	pthread_mutex_lock(philo->right_fork);
	ft_print_eating(philo);
	pthread_mutex_lock(&philo->status);
	philo->last_meal = ft_gettime(philo);
	pthread_mutex_unlock(&philo->status);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->status);
	if (philo->optionnal == 1)
		philo->nb_of_meal--;
	pthread_mutex_unlock(&philo->status);
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
	long long	time;
	long long	nb;

	ft_print_sleeping(philo);
	pthread_mutex_lock(&philo->status);
	time = (philo->last_meal + philo->time_to_die);
	nb = (time - (ft_gettime(philo) + philo->time_to_sleep));
	if (nb <= 0)
	{
		ft_usleep(time - ft_gettime(philo), philo);
		philo->life = 0;
		ft_print_die(philo);
		pthread_mutex_unlock(&philo->status);
		return (1);
	}
	pthread_mutex_unlock(&philo->status);
	ft_usleep(philo->time_to_sleep, philo);
	return (0);
}

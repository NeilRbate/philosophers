/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:32:41 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/17 08:41:14 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_waiteat(t_philo *philo)
{
	pthread_mutex_unlock(&philo->status);
	while (1)
	{
	}
}

int	ft_diealone(t_philo *philo)
{
	ft_usleep(philo->time_to_die, philo);
	if (pthread_mutex_lock(philo->print) != 0)
		return (1);
	pthread_mutex_unlock(philo->right_fork);
	if (pthread_mutex_lock(&philo->status) != 0)
		return (1);
	philo->life = 0;
	pthread_mutex_unlock(&philo->status);
	printf("%lld %d died\n", ft_gettime(philo), philo->nb);
	return (1);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (ft_print_fork(philo) != 0)
		return (1);
	if (philo->left_fork == philo->right_fork)
		return (ft_diealone(philo));
	pthread_mutex_lock(philo->right_fork);
	if (ft_print_eating(philo) != 0)
		return (pthread_mutex_unlock(philo->right_fork), 1);
	pthread_mutex_lock(&philo->status);
	philo->last_meal = ft_gettime(philo);
	if (philo->optionnal == 1)
		philo->nb_of_meal--;
	pthread_mutex_unlock(&philo->status);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	ft_thinking(t_philo *philo)
{
	if (ft_print_thinking(philo) != 0)
		return (1);
	usleep(50);
	return (0);
}

int	ft_sleeping(t_philo *philo)
{
	long long	time;
	long long	nb;

	if (ft_print_sleeping(philo) != 0)
		return (1);
	pthread_mutex_lock(&philo->status);
	time = (philo->last_meal + philo->time_to_die);
	nb = (time - (ft_gettime(philo) + philo->time_to_sleep));
	pthread_mutex_unlock(&philo->status);
	if (nb <= 0)
	{
		ft_usleep(time - ft_gettime(philo), philo);
		if (pthread_mutex_lock(philo->print) != 0)
			return (1);
		if (pthread_mutex_lock(&philo->status) != 0)
			return (1);
		philo->life = 0;
		pthread_mutex_unlock(&philo->status);
		printf("%lld %d died\n", ft_gettime(philo), philo->nb);
		pthread_mutex_destroy(philo->print);
		return (1);
	}
	ft_usleep(philo->time_to_sleep, philo);
	return (0);
}

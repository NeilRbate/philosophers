/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:47:09 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/15 12:41:57 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d has taken a fork\n", ft_gettime(philo), philo->nb);
	pthread_mutex_unlock(philo->print);
}

void	ft_print_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d is eating\n", ft_gettime(philo), philo->nb);
	pthread_mutex_unlock(philo->print);
}

void	ft_print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d is sleeping\n", ft_gettime(philo), philo->nb);
	pthread_mutex_unlock(philo->print);
}

void	ft_print_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d is thinking\n", ft_gettime(philo), philo->nb);
	pthread_mutex_unlock(philo->print);
}

void	ft_print_die(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%lld %d died\n", ft_gettime(philo), philo->nb);
	pthread_mutex_unlock(philo->print);
}

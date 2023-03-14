/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:46:53 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/14 10:54:00 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_start(t_philo *philo)
{

}

void	*ft_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo*)p;
	usleep(100);
	while (1)
	{
		if (philo->life != 1)
			return (0);
		ft_start(philo);
	}
	return (0);
}

void	ft_wait(t_philo **philo, int nb)
{
	int i;

	i = 0;
	while (1)
	{
		if (i == nb)
			i = 0;
		if (philo[i]->life == 0)
		{
			i = 0;
			while (i < nb)
			{
				pthread_detach(philo[i]->tid);
				i++;
			}
			break;
		}
		i++;
	}
}

int	ft_exec(t_philo **philo)
{
	int	nb;
	int	i;

	nb = philo[0]->nb_of_philo;
	i = 0;
	while (i < nb)
	{
		gettimeofday(&philo[i]->time, NULL);
		pthread_create(&philo[i]->tid, NULL, ft_routine, philo[i]);
		i++;
	}
	ft_wait(philo, nb);
	pthread_mutex_destroy(philo[0]->print);
	usleep(20000);
	return (0);
}

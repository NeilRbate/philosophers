/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:46:53 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/16 09:59:57 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	if (philo->nb % 2 == 0)
		usleep(150);
	while (1)
	{
		if (philo->life != 1)
			return (0);
		pthread_mutex_lock(&philo->status);
		if (philo->nb_of_meal > 0)
		{
			pthread_mutex_unlock(&philo->status);
			if (ft_eat(philo) != 0)
				return (0);
		}
		else
			ft_waiteat(philo);
		if (ft_sleeping(philo) != 0)
			return (0);
		if (ft_thinking(philo))
			return (0);
	}
	return (0);
}

int	ft_isalleat(t_philo **philo, int j, int nb)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		while (i < nb)
		{
			pthread_detach(philo[i]->tid);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_check(t_philo **philo, int *j, int *i, int nb)
{
	pthread_mutex_lock(&philo[*i]->status);
	if (philo[*i]->nb_of_meal > 0)
		*j += 1;
	if (philo[*i]->life == 0)
	{
		pthread_mutex_destroy(philo[*i]->print);
		*i = 0;
		pthread_mutex_unlock(&philo[*i]->status);
		while (*i < nb)
		{
			pthread_detach(philo[*i]->tid);
			*i += 1;
		}
		return (1);
	}
	pthread_mutex_unlock(&philo[*i]->status);
	return (0);
}

void	ft_wait(t_philo **philo, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (1)
	{
		if (i == nb)
		{
			if (j == 0)
				if (ft_isalleat(philo, j, nb) == 1)
					return ;
			j = 0;
			i = 0;
		}
		if (ft_check(philo, &j, &i, nb) == 1)
			return ;
		i++;
	}
}

int	ft_exec(t_philo **philo)
{
	int				nb;
	int				i;
	struct timeval	time;

	nb = philo[0]->nb_of_philo;
	i = 0;
	gettimeofday(&time, NULL);
	while (i < nb)
		philo[i++]->time = time;
	i = 0;
	while (i < nb)
	{
		pthread_create(&philo[i]->tid, NULL, ft_routine, philo[i]);
		usleep(150);
		pthread_detach(philo[i]->tid);
		i++;
	}
	ft_wait(philo, nb);
	pthread_mutex_destroy(&philo[0]->status);
	return (0);
}

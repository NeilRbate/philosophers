/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:13:49 by jbarbate          #+#    #+#             */
/*   Updated: 2023/02/06 11:53:01 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*ft_init_philo(t_data *data, pthread_mutex_t *mutex, int i)
{
	t_philo	*philo;

	philo = malloc(sizeof(*philo));
	if (!philo)
		return (NULL);
	philo->mutex = mutex;
	philo->data = data;
	philo->nb = i + 1;
	philo->right_fork = i + 1;
	if (i == data->nb_of_philo - 1)
		philo->right_fork = 1;
	philo->right_fork = i + 1;
	return (philo);
}

int	ft_create_thread(t_data *data, pthread_mutex_t *fork)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->nb_of_philo)
	{
		philo = ft_init_philo(data, fork, i);
		pthread_create(&philo->tid, NULL, ft_philosopher_life, philo);
		i++;
	}
		pthread_detach(philo->tid);
	return (0);
}

pthread_mutex_t	*ft_create_fork(t_data *data)
{
	int				i;
	pthread_mutex_t	*tab;

	tab = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_mutex_init(&tab[i], NULL);
		i++;
	}
	return (tab);
}

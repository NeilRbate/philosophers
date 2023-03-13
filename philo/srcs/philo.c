/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:13:49 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/13 15:09:44 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*ft_create_philo(t_data *data, int nb)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	pthread_mutex_init(&philo->fork, NULL);
	philo->nb = nb + 1;
	philo->nb_of_philo = data->nb_of_philo;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->optionnal = data->optionnal;
	if (philo->optionnal > 0)
		philo->nb_of_meal = data->nb_of_meal;
	if (nb == 0)
		philo->left_fork = philo->nb_of_philo;
	else
		philo->left_fork = nb - 1;
	if (nb + 1 == philo->nb_of_philo)
		philo->right_fork = 1;
	else
		philo->right_fork = nb + 2;
	return (philo);
}

int	ft_init_philo(t_data *data, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		philo[i] = ft_create_philo(data, i);
		if (!philo[i])
			return (-1);
		i++;
	}
	return (0);
}

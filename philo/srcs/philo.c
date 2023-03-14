/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:13:49 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/14 17:09:32 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_init(t_data *data, t_philo *philo, int nb)
{
	philo->nb = nb + 1;
	philo->life = 1;
	philo->nb_of_philo = data->nb_of_philo;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->optionnal = data->optionnal;
	if (philo->optionnal > 0)
		philo->nb_of_meal = data->nb_of_meal;
	else
		philo->nb_of_meal = 2147483640;

}

t_philo	*ft_create_philo(t_data *data, int nb, pthread_mutex_t *print)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	pthread_mutex_init(&philo->fork, NULL);
	ft_init(data, philo, nb);
	philo->print = print;
	return (philo);
}

int	ft_init_philo(t_data *data, t_philo **philo, pthread_mutex_t *print)
{
	int	i;
	int	nb;

	i = 0;
	nb = data->nb_of_philo;
	while (i < nb)
	{
		philo[i] = ft_create_philo(data, i, print);
		if (!philo[i])
			return (-1);
			i++;
	}
	i = 0;
	while (i < nb)
	{
		if (i == 0)
			philo[i]->left_fork = &philo[nb - 1]->fork;
		else
			philo[i]->left_fork = &philo[i - 1]->fork;
		if (i + 1 == nb)
			philo[i]->right_fork = &philo[0]->fork;
		else
			philo[i]->right_fork = &philo[i + 1]->fork;
		i++;
	}
	return (0);
}

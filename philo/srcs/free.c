/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:36:34 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/14 09:40:46 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free_philo(t_philo **philo)
{
	int	nb;

	nb = philo[0]->nb_of_philo - 1;
	while (nb >= 0)
	{
		free(philo[nb]);
		nb--;
	}
	free(philo);
	philo = NULL;
}

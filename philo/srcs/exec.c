/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:46:53 by jbarbate          #+#    #+#             */
/*   Updated: 2023/02/06 11:49:17 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>
void	*ft_philosopher_life(void *philo)
{
	t_philo	*p;

	printf("Coucou \n");
	p = philo;
	p->nb = 5;
	usleep(1000);
	usleep(1000);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:57:52 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/13 15:07:50 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	int	ret;
	t_data	*data;
	t_philo	**philo;

	if (argc < 5 || argc > 7)
		return (-1);
	data = malloc(sizeof(*data));
	ret = ft_args_ctrl(argc, argv + 1, data);
	if (ret != 0)
		return (free(data), -1);
	philo = malloc(sizeof(t_philo) * data->nb_of_philo);
	if (!philo)
		return (free(data), -1);
	if (ft_init_philo(data, philo) != 0)
		return (free(data), -1);
	printf("philo 1 fork->%d", philo[0]->right_fork);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:57:52 by jbarbate          #+#    #+#             */
/*   Updated: 2023/02/06 11:46:59 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	int				ret;
	t_data			*data;
	pthread_mutex_t	*fork;

	if (argc < 5 || argc > 7)
		return (-1);
	data = malloc(sizeof(*data));
	ret = ft_args_ctrl(argc, argv + 1, data);
	if (ret != 0)
		return (-1);
	fork = ft_create_fork(data);
	if (!fork)
		return (free(data), -1);
	printf("sme\n");
	ft_create_thread(data, fork);


}

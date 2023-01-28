/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:57:52 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/28 14:42:02 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	int	ret;
	t_data	*data;

	if (argc < 5 || argc > 7)
		return (-1);
	data = malloc(sizeof(*data));
	ret = ft_args_ctrl(argc, argv + 1, data);
	if (ret != 0)
		return (-1);
}

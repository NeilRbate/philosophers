/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:03:53 by jbarbate          #+#    #+#             */
/*   Updated: 2023/02/06 08:26:31 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print_error(void)
{
	printf("error: invalid arguments\n");
}

int	ft_init_data(t_data *data, int argc, char **argv)
{
	data->nb_of_philo = ft_atoi(argv[0]);
	if (data->nb_of_philo == 0)
		return (-1);
	data->time_to_die = ft_atoi(argv[1]);
	data->time_to_eat = ft_atoi(argv[2]);
	data->time_to_sleep = ft_atoi(argv[3]);
	data->nb_of_eat = 0;
	if (argc == 5)
	{
		data->optionnal = 1;
		data->nb_of_meal = ft_atoi(argv[4]);
	}
	return (0);
}

int	ft_value_ctrl(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 1 && str[0] == '0')
		while (str[i] == '0' && str[i])
			i++;
	if (str[i] == '\0')
		return (0);
	str += i;
	i = 0;
	if (ft_strlen(str) > 10)
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (-1);
		i++;
	}
	if (ft_strlen(str) == 10 && ft_strcmp(str, "2147483647") > 0)
		return (-1);
	return (0);
}

int	ft_args_ctrl(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_value_ctrl(argv[i]) != 0)
			return (ft_print_error(), -1);
		i++;
	}
	return (ft_init_data(data, i, argv));
}

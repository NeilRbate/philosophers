/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:02:50 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/13 15:04:59 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_data
{
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	optionnal;
	int	nb_of_meal;
}			t_data;

typedef struct	s_philo
{
	pthread_t	tid;
	pthread_mutex_t	fork;
	int		nb;
	int		nb_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		optionnal;
	int		nb_of_meal;
	int		right_fork;
	int		left_fork;
}		t_philo;
int	ft_init_philo(t_data *data, t_philo **philo);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	ft_args_ctrl(int argc, char **argv, t_data *data);
size_t	ft_strlen(const char *s);

#endif

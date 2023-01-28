/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:02:50 by jbarbate          #+#    #+#             */
/*   Updated: 2023/01/28 14:40:20 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_data
{
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	optionnal;
	int	nb_of_meal;
}		t_data;

int     ft_strcmp(const char *s1, const char *s2);
int     ft_atoi(const char *str);
int     ft_isdigit(int c);
int     ft_args_ctrl(int argc, char **argv, t_data *data);
size_t  ft_strlen(const char *s);

#endif

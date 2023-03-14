/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:02:50 by jbarbate          #+#    #+#             */
/*   Updated: 2023/03/14 16:47:25 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*For printf*/
# include <stdio.h>
/*For malloc & cie*/
# include <stdlib.h>
/*For thread*/
# include <pthread.h>
/*For usleep*/
# include <unistd.h>
/*For gettimeofday */
# include <sys/time.h>

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
	pthread_t		tid;
	pthread_mutex_t	fork;
	pthread_mutex_t	*print;
	int				nb;
	int				life;
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				optionnal;
	int				nb_of_meal;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			*left_fork;
	struct timeval	time;
}		t_philo;
int		ft_init_philo(t_data *data, t_philo **philo, pthread_mutex_t *print);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_args_ctrl(int argc, char **argv, t_data *data);
int		ft_exec(t_philo **philo);
size_t	ft_strlen(const char *s);
long long	ft_gettime(t_philo *philo);
void	ft_print_fork(t_philo *philo);
void	ft_print_eating(t_philo *philo);
void	ft_print_sleeping(t_philo *philo);
void	ft_print_thinking(t_philo *philo);
void	ft_print_die(t_philo *philo);
void	ft_free_philo(t_philo **philo);
int	ft_eat(t_philo *philo);
int	ft_thinking(t_philo *philo);
int	ft_sleeping(t_philo *philo);
int	ft_usleep(long time);
#endif

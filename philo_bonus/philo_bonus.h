/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:35:55 by lgyger            #+#    #+#             */
/*   Updated: 2022/01/12 18:42:05 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct s_all
{
	pid_t	*pid;
	sem_t	*forks;
	sem_t	*meals;
	int		nb_phi;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	long	t_start;
	sem_t	*mess;
	int		nb_eat;
	long	last_meal;
	int		meal_cnt;
	int		who;
	int		finish;
}				t_all;
void				ft_memstruct(t_all *all, char **argv);
int					arg_check(int ac, char **av);
void				ft_message(long time, int who, char *what, sem_t *mess);
long				ft_time(void);
void				ft_usleep(int length);
int					ft_atoi(char *str);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:32:18 by lgyger            #+#    #+#             */
/*   Updated: 2022/01/12 18:41:40 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*meal_loop(void *ptr)
{
	t_all	*s;
	int		i;

	s = (t_all *)ptr;
	i = 0;
	while (i < s->nb_phi)
	{
		sem_wait(s->meals);
		i++;
	}
	i = -1;
	ft_message(s->t_start, 0, "Everyone has eaten enough !", s->mess);
	while (++i < s->nb_phi)
		kill(s->pid[i], SIGTERM);
	free(s->pid);
	sem_unlink("forks");
	sem_unlink("meals");
	exit(0);
	return (NULL);
}

void	*death_loop(void *ptr)
{
	t_all	*s;
	int		check;
	int		i;

	i = 0;
	s = (t_all *)ptr;
	check = 1;
	while (1)
	{
		if (ft_time() - s->last_meal >= s->t_die)
		{
			ft_message(s->t_start, s->who, "has died", s->mess);
			exit(0);
		}
		else if (s->nb_eat != -1 && s->meal_cnt >= s->nb_eat && check)
		{
			sem_post(s->meals);
			check = 0;
			return (NULL);
		}
	}
	return (NULL);
}

void	philosopher(t_all s)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, death_loop, &s);
	while (1)
	{
		sem_wait(s.forks);
		ft_message(s.t_start, s.who, "has taken a fork", s.mess);
		ft_message(s.t_start, s.who, "has taken a fork", s.mess);
		s.last_meal = ft_time();
		ft_message(s.t_start, s.who, "is eating", s.mess);
		ft_usleep(s.t_eat);
		s.meal_cnt++;
		sem_post(s.forks);
		ft_message(s.t_start, s.who, "is sleeping", s.mess);
		ft_usleep(s.t_sleep);
		ft_message(s.t_start, s.who, "is thinking", s.mess);
	}
}

void	philo_three(t_all s)
{
	int			i;
	pthread_t	tid;

	i = 0;
	s.pid = malloc(sizeof(pid_t) * s.nb_phi);
	while (i < s.nb_phi)
	{
		s.pid[i] = fork();
		if (s.pid[i] == 0)
		{
			s.who = i + 1;
			philosopher(s);
			i = s.nb_phi;
		}
		i++;
	}
	if (s.nb_eat > -1)
		pthread_create(&tid, NULL, meal_loop, &s);
	waitpid(-1, NULL, 0);
	i = 0;
	while (i < s.nb_phi)
		kill(s.pid[i++], SIGTERM);
	free(s.pid);
}

int	main(int ac, char **av)
{
	t_all	s;

	if (arg_check(ac, av) == 0)
		return (1);
	ft_memstruct(&s, av);
	s.t_start = ft_time();
	s.last_meal = s.t_start;
	s.meal_cnt = 0;
	sem_unlink("forks");
	sem_unlink("meals");
	sem_unlink("mess");
	s.forks = sem_open("forks", O_CREAT, S_IRWXU, (s.nb_phi / 2));
	s.meals = sem_open("meals", O_CREAT, S_IRWXU, 0);
	s.mess = sem_open("mess", O_CREAT, S_IRWXU, 1);
	philo_three(s);
	sem_close(s.forks);
	sem_close(s.meals);
	sem_close(s.mess);
	sem_unlink("forks");
	sem_unlink("meals");
	return (0);
}

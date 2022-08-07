/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:36:20 by lgyger            #+#    #+#             */
/*   Updated: 2021/12/07 13:52:57 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo(void *arg);

int	get_time(void)
{
	struct timeval	tv;
	int				i;

	gettimeofday(&tv, NULL);
	i = tv.tv_usec / 1000 + tv.tv_sec * 1000;
	return (i);
}

void	*ded(void *arg)
{
	t_philo	*ph;

	ph = arg;
	while (!ph->args->finish)
	{
		pthread_mutex_lock(&ph->t_leat);
		if (!ph->args->finish && (get_time() - 5) - ph->der > ph->args->ttodie)
		{
			pthread_mutex_unlock(&ph->t_leat);
			putph(ph, 5);
			return (NULL);
		}
		pthread_mutex_unlock(&ph->t_leat);
		usleep(100);
	}
	return (NULL);
}

void	init_threads(t_args *args)
{
	int			i;
	pthread_t	tid;

	i = 0;
	args->time = get_time ();
	while (i < args->nbrph)
	{
		args->philo[i].der = get_time ();
		pthread_create(&tid, NULL, philo,
			(void *)&args->philo[i]);
		pthread_detach(tid);
		if (pthread_create(&args->philo[i].thread, NULL,
				&ded, (void*)&args->philo[i]))
			return ;
		usleep(1000);
		i++;
	}
	i = 0;
	while (i < args->nbrph)
	{
		pthread_join(args->philo[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char *argv[])
{
	t_args	args;

	memset(&args, 0, sizeof(t_args));
	if (ac < 5 || ac > 6)
	{
		write(2, "You need at least 4 args and not more than 5 args", 49);
		return (1);
	}
	args.nbrph = ft_atoi(argv[1]);
	args.ttodie = ft_atoi(argv[2]);
	args.ttoeat = ft_atoi(argv[3]);
	args.ttosleep = ft_atoi(argv[4]);
	mem_ph(&args);
	if (ac == 6)
		args.nbreat = ft_atoi(argv[5]);
	init_threads(&args);
	return (0);
}

void	*philo(void *arg)
{
	t_philo	*ph;

	ph = arg;
	ph->der = get_time ();
	while (!ph->args->finish)
	{
		ft_fork(ph);
		if (ph->args->finish)
			break ;
		miam(ph);
		if (ph->args->finish)
			break ;
		ft_fork_n(ph);
		if (ph->args->nbreat > 0 && check_ph(ph))
			break ;
		if (ph->args->finish)
			break ;
		dodo(ph);
		putph(ph, 4);
	}
	pthread_mutex_unlock(&ph->args->fork[ph->frk_l]);
	pthread_mutex_unlock(&ph->args->fork[ph->frk_r]);
	pthread_mutex_unlock(&ph->args->lock);
	return (NULL);
}

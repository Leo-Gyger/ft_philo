/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:30:13 by lgyger            #+#    #+#             */
/*   Updated: 2021/12/06 20:46:20 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

unsigned int	ft_atoi(const char *str)
{
	unsigned int	res;
	int				i;

	res = 0;
	i = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return (res);
}

int	mem_ph(t_args *args)
{
	int	i;

	i = -1;
	args->philo = malloc(sizeof(t_args) * args->nbrph);
	args->fork = malloc(sizeof(pthread_mutex_t) * args->nbrph);
	if (!args->philo || !args->fork)
		return (1);
	while (++i < args->nbrph)
	{
		args->philo[i].nb = i;
		args->philo[i].tour = 0;
		args->philo[i].frk_l = i;
		args->philo[i].frk_r = (i + 1) % args->nbrph;
		pthread_mutex_init(&args->philo[i].t_leat, NULL);
		args->philo[i].args = args;
		pthread_mutex_init(&args->fork[i], NULL);
	}
	pthread_mutex_init(&args->lock, NULL);
	return (0);
}

int	check_ph(void *args)
{
	t_philo	*ph;

	ph = args;
	if (ph->tour >= ph->args->nbreat)
		ph->args->a++;
	if (ph->args->a == ph->args->nbrph)
	{
		putph(ph, 6);
		return (1);
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

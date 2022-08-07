/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:35:52 by lgyger            #+#    #+#             */
/*   Updated: 2021/12/07 13:52:39 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_fork(t_philo *ph)
{
	pthread_mutex_lock(&ph->args->fork[ph->frk_l]);
	putph(ph, 1);
	pthread_mutex_lock(&ph->args->fork[ph->frk_r]);
	putph(ph, 1);
}

void	miam(t_philo *ph)
{
	putph(ph, 2);
	ph->der = get_time();
	pthread_mutex_lock(&ph->t_leat);
	usleep(ph->args->ttoeat * 1000);
	ph->tour++;
	pthread_mutex_unlock(&ph->t_leat);
}

void	ft_fork_n(t_philo *ph)
{
	pthread_mutex_unlock(&ph->args->fork[ph->frk_l]);
	pthread_mutex_unlock(&ph->args->fork[ph->frk_r]);
}

void	dodo(t_philo *ph)
{
	putph(ph, 3);
	usleep(ph->args->ttosleep * 1000);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:35:27 by lgyger            #+#    #+#             */
/*   Updated: 2021/12/06 16:35:44 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_ph(t_args *args)
{
	int	i;

	i = 0;
	if (args)
	{
		if (args->fork)
		{
			while (i < args->nbrph)
				pthread_mutex_destroy(&args->fork[i++]);
			free(args->fork);
		}
		pthread_mutex_destroy(&args->lock);
		if (args->philo)
		{
			i = 0;
			while (i < args->nbrph)
				pthread_mutex_destroy(&args->philo[i++].t_leat);
			free(args->philo);
			args->philo = NULL;
		}
	}
	return ;
}

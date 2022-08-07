/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:30:04 by lgyger            #+#    #+#             */
/*   Updated: 2021/12/06 20:54:19 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

char	*print(int no)
{
	if (no == 1)
		return (" has taken a fork\n");
	else if (no == 2)
		return (" is eating \n");
	else if (no == 3)
		return (" is sleeping\n");
	else if (no == 4)
		return (" is thinking\n");
	else if (no == 5)
		return (" got oofed(died)\n");
	return (" limits of meal reached\n");
}

void	putph(t_philo *ph, int no)
{
	char	*tmp;

	pthread_mutex_lock(&ph->args->lock);
	if (!ph->args->finish)
	{
		tmp = print(no);
		ft_putnbr(get_time() - ph->args->time);
		if (no != 6)
		{
			write(1, "\tPhilosopher ", 13);
			ft_putnbr(ph->nb + 1);
		}
		write(1, tmp, ft_strlen(tmp));
		tmp = NULL;
		if (no == 5 || no == 6)
		{
			ph->args->finish = 1;
			return ;
		}
	}
	pthread_mutex_unlock(&ph->args->lock);
}

void	ft_putnbr(int i)
{
	if (i < 0)
	{
		i *= -1;
		ft_putchar('-');
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		ft_putchar(i + '0');
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

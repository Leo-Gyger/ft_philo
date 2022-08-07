/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:58:13 by lgyger            #+#    #+#             */
/*   Updated: 2021/12/06 16:35:18 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <string.h> 

typedef struct s_philo
{
	int				nb;
	int				tour;
	int				der;
	int				frk_l;
	int				frk_r;
	pthread_t		thread;
	pthread_mutex_t	t_leat;
	struct s_args	*args;
}					t_philo;

typedef struct s_args
{
	int				nbrph;
	int				ttodie;
	int				ttoeat;
	int				ttosleep;
	int				time;
	int				nbreat;
	int				finish;
	int				a;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
}	t_args;
unsigned int	ft_atoi(const char *str);
int				mem_ph(t_args *args);
int				check_ph(void *args);
void			putph(t_philo *ph, int no);
void			ft_fork(t_philo *ph);
void			dodo(t_philo *ph);
void			eat(t_philo *ph);
void			ft_fork_n(t_philo *ph);
void			miam(t_philo *ph);
int				get_time(void);
size_t			ft_strlen(char *s);
void			ft_putnbr(int i);
void			ft_putchar(char c);
void			clean_ph(t_args *args);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:58:35 by azod              #+#    #+#             */
/*   Updated: 2021/03/03 15:54:14 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philtwo.h"

int is_alive(t_philos *p)
{
	double deadtime;

	sem_wait(p->mutex);
	deadtime = p->deadtime;
	if (deadtime == -1)
	{
		sem_post(p->mutex);
		return (1);
	}
	if (!check_time(deadtime, get_p(NULL)))
	{
		sem_post(p->mutex);
		return (0);
	}
	sem_post(p->mutex);
	return (1);
}

static void sleeping(t_philos *p)
{
	sem_wait(p->mutex);
	if (is_alive(p))
		print_action(p, "is sleeping");
	usleep(get_p(NULL)->tts * 1000);
	sem_post(p->mutex);
}

static void try_to_eat(t_philos *p)
{
	p->eat -= 1;
	print_action(p, "eat");
	p->deadtime = get_time(get_p(NULL)) + get_p(NULL)->ttd;
	usleep(get_p(NULL)->tte * 1000);
	sem_post(get_p(NULL)->forks);
	sem_post(get_p(NULL)->forks);
	if (get_p(NULL)->end)
		return;
}

static void wait_forks(t_philos *p)
{
	sem_wait(get_p(NULL)->forks);
	if (get_p(NULL)->end)
		return;
	print_action(p, "has taken a fork");
	sem_wait(get_p(NULL)->forks);
	if (get_p(NULL)->end)
		return;
	print_action(p, "has taken a fork");
}

void *simulate(void *philo)
{
	t_philos **p;

	p = philo;
	while (get_p(NULL)->end == 0 && (*p)->eat != 0)
	{
		print_action(*p, "is thinking");
		wait_forks(*p);
		if (get_p(NULL)->end)
			return (NULL);
		try_to_eat(*p);
		if (get_p(NULL)->end)
			return (NULL);
		if ((*p)->eat)
			sleeping(*p);
	}
	(*p)->deadtime = -1;
	return (philo);
}

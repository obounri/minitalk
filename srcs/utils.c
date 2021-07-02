/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:10:56 by obounri           #+#    #+#             */
/*   Updated: 2021/06/19 17:17:49 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	encode(char *mess, int pid)
{
	int		bit;
	int		i;
	int		count;
	char	c;

	i = 0;
	while (mess[i] != '\0')
	{
		count = 0;
		bit = 1;
		c = mess[i];
		while (count < 8)
		{
			if (c & bit)
				kill(pid, SIGUSR2);
			else if ((c & bit) == 0)
				kill(pid, SIGUSR1);
			usleep(75);
			count++;
			bit = bit * 2;
		}
		i++;
	}
	return (1);
}

void	decode(int sig)
{
	static int	count = 0;
	static char	c = 0;
	static int	bit = 0;

	if (count < 8)
	{
		if (sig == SIGUSR2)
			c |= 1 << bit;
		bit++;
		count++;
	}
	if (count == 8)
	{
		ft_putchar_fd(c, 1);
		count = 0;
		bit = 0;
		c = 0;
	}
}

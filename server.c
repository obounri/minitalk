/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:42:29 by obounri           #+#    #+#             */
/*   Updated: 2021/06/17 16:10:13 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void    decode(int sig)
{
    static int  count = 0;
    static char c = 0;
    static int  bit = 0;

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

int main()
{
    int pid;
    int time;

    time = 0;
    // count = 0;
    pid = getpid();
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    signal(SIGUSR1, &decode);
    signal(SIGUSR2, &decode);
    while (1)
        pause();
    return (0);
}
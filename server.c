/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:42:29 by obounri           #+#    #+#             */
/*   Updated: 2021/06/15 17:22:44 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void    sighandler(int sig)
{
    static int count = 0; 
    // static int count;

    // printf("received %d\n", sig);
    // printf("count is now : [%d]\n", dec_count);
    if (count < 8)
    {
        if (sig == SIGUSR1)
            ft_putnbr_fd(0, 1);
        else if (sig == SIGUSR2)
            ft_putnbr_fd(1, 1);
        count++;
    }
    if (count == 8)
    {
        ft_putchar_fd(' ', 1);
        count = 0;
    }
    // count++;
}

int main()
{
    int pid;

    pid = getpid();
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    signal(SIGUSR1, &sighandler);
    signal(SIGUSR2, &sighandler);
    while (1)
        pause();
    return (0);
}
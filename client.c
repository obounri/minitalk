/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:23:14 by obounri           #+#    #+#             */
/*   Updated: 2021/06/17 15:34:23 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //
#include <unistd.h>
#include <signal.h>
#include "srcs/libft/libft.h"

int encode(char *mess, int pid)
{
    int bit;
    int i;
    int count;
    char c;
    
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
            usleep(50);
            count++;
            bit = bit * 2;
        }
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    int pid;

    pid = ft_atoi(av[1]);
    if ((ac == 3) && (kill(pid, 0) != -1))
        encode(av[2], pid);
    else
        ft_putstr_fd("Error\n", 1);

    return (0);
}
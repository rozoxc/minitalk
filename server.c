/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:35:07 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/21 00:34:50 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int signal, siginfo_t *info , void *content)
{
    static int bit = 0;
    static char c = 0;
    static pid_t pid;

	(void)content;
    if (pid == 0)
        pid = info->si_pid;
    if (info->si_pid != pid)
    {
        pid = 0;
        bit = 0;
        c = 0;
    }
    if (signal == SIGUSR1)
    {
        c |= (1 << bit);
    }
    bit++;
    if (bit == 8)
    {
        write(1, &c, 1);
        bit = 0;
        c = 0;
    }
}

int main(int ac, char **av)
{
    struct sigaction sa;
    (void)av;

    if (ac != 1)
    {
        ft_printf("error !!");
        return (1);
    }
    ft_printf("PID : ");
    ft_printf("%d\n", getpid());

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:35:01 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/16 15:20:41 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
    int	bit;

    bit = 0;
    while (bit < 8)
    {
        if (c & (1 << bit))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);// kana3so 100 microseconde 
        bit++;
    }
}

int	main(int argc, char **argv)
{
    pid_t	server_pid;
    char	*message;
    int		i;

    if (argc != 3)
    {
        ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return (1);
    }

    server_pid = ft_atoi(argv[1]);
    message = argv[2];
    i = 0;

    while (message[i] != '\0')
    {
        send_char(server_pid, message[i]);
        i++;
    }

    return (0);
}

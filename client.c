/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:35:01 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/21 00:22:30 by ababdoul         ###   ########.fr       */
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
		usleep(255);
		bit++;
	}
}
int check_av(char *str)
{
	int	i;
	int	found_digit;

	i = 0;
	found_digit = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!str[i] || str[i] < '0' || str[i] > '9')
			return (0);
		found_digit = 1;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	return (found_digit);
}
int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		ft_printf("Example : ./client 2222 \"your_message ;)\" ");
		return (1);
	}
	if (check_av(argv[1]) == 0)
	{
		ft_printf("invalid pid :( \n");
		return (1);
	}
	
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i] != '\0')
	{
		send_char(server_pid, message[i]);
		usleep(25);
		i++;
	}
	return (0);
}

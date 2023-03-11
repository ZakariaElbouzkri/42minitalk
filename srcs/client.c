/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:26:27 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/11 02:53:45 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	send_sig(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	client(pid_t pid, char *str)
{
	while (*str)
	{
		send_sig(pid, *str);
		str++;
	}
	ft_putstr_fd("Message sent\n", 1);
}

int main(int ac, char	**av)
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (kill(pid, 0) != 0)
			ft_perror("pid");
		client(pid, av[2]);
	}
	else
	{
		ft_printf("client programe need 2 parameters\n");
		ft_printf("./client \"server_pid\" \"message\"\n");
	}
}
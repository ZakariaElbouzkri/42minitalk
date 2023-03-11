/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:26:27 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/11 02:39:29 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

static int	ft_is_space(char c)
{
	return (c == '\f' || c == '\t' || c == ' '
		|| c == '\n' || c == '\r' || c == '\v');
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		else if (*str == '+')
			sign = 1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		res *= 10;
		res += (*str) - 48;
		str++;
	}
	res = res * sign;
	return (res);
}


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
	ft_putstr("Message sent\n");
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
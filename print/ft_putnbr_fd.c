/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:49:51 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/11 02:32:57 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;
	int				len;

	len = 0;
	a = n;
	if (n < 0)
	{
		len += ft_putchar_fd('-', fd);
		a *= -1;
	}
	if (a < 10)
		len += ft_putchar_fd(a + '0', fd);
	else
	{
		len += ft_putnbr_fd((a / 10), fd);
		len += ft_putnbr_fd((a % 10), fd);
	}
	return (len);
}

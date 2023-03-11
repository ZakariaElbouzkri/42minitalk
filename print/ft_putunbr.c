/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:24 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/11 02:33:07 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putunbr(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n < 10)
		len += ft_putchar_fd(n + 48, fd);
	else
	{
		len += ft_putunbr((n / 10), fd);
		len += ft_putunbr((n % 10), fd);
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:28:23 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/11 02:33:03 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putptr(unsigned long n, int fd)
{
	int	len;

	len = 0;
	len += ft_putstr_fd("0x", fd);
	len += ft_puthexa(n, fd, 'x');
	return (len);
}

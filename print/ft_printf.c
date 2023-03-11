/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 02:21:55 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/11 02:32:49 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_is_format(char c)
{
	if ((c == 'd') || (c == 's') || (c == 'i') || (c == 'p') || (c == '%'))
		return (1);
	else if ((c == 'x') || (c == 'X') || (c == 'u') || (c == 'c'))
		return (1);
	return (0);
}

static int	ft_check(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 'd' || (c == 'i'))
		len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if ((c == 'x') || (c == 'X'))
		len += ft_puthexa(va_arg(args, unsigned int), 1, c);
	else if (c == 'p')
		len += ft_putptr(va_arg(args, unsigned long), 1);
	else if (c == 'u')
		len += ft_putunbr(va_arg(args, unsigned int), 1);
	else if (c == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_is_format(format[i + 1]))
				len += ft_check(args, format[i + 1]);
			else
				len += ft_putchar_fd(format[i + 1], 1);
			i++;
		}
		else
			len += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

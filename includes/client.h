/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:14:57 by zel-bouz          #+#    #+#             */
/*   Updated: 2023/03/11 03:00:00 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
#define CLIENT_H

# include "ft_printf.h"
# include <signal.h>

void	client(pid_t pid, char *str);
void	send_sig(int pid, char c);

#endif

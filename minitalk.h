/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:30:39 by ababdoul          #+#    #+#             */
/*   Updated: 2025/01/15 21:51:27 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 # ifndef MINITALK_H
 #  define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include <stdarg.h>

int	ft_atoi(const char *str);
int				ft_putchar(int c);
int				ft_putnbr(int nb);
int				ft_putstr(char *str);
int				ft_printf(const char *s, ...);
size_t			ft_strlen(const char *s);
int				convert_hex(unsigned int n);
int				print_addr(unsigned long num);
int				ft_convert_hex(unsigned int n);
unsigned int	ft_unsigned(unsigned int nb);
#endif
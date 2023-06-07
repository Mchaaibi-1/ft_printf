/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:28:13 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/06/07 13:41:38 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putchar(char a, int *l);
void	ft_putnbr(long n, int *l);
void	ft_putstr(char *s, int *l);
void	ft_hexalow(unsigned long d, int *l);
void	ft_hexaup(unsigned int d, int *l);
int		ft_printf(const char *print, ...);
void	handle_specifier(char spec, va_list past, int *l);
void	unsignedecimal(unsigned int x, int *l);

#endif
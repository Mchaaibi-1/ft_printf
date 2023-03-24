/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:35:53 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/03/23 17:37:27 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *print, ...)
{
	va_list	past;

	int	j;

	int	l;
	l = 0;
	j = 0;
	va_start(past, print);
	while (print[j])
	{
		if (print[j] == '%')
		{
			j++;
			if (print[j] == 'c')
				ft_putchar(va_arg (past, int));
			else if (print[j] == '%')
				ft_putchar('%');
			else if (print[j] == 's')
				ft_putstr(va_arg (past, char *), &l);
			else if (print[j] == 'd')
				ft_putnbr(va_arg (past, int));
			else if (print[j] == 'i')
				ft_putnbr(va_arg(past, int));
			else if (print[j] == 'x')
				ft_hexalow(va_arg(past, unsigned int), &l);
			else if (print[j] == 'X')
				ft_hexaup(va_arg(past, unsigned int), &l);
			else if (print[j] == 'p')
			{
				ft_putstr("0x", &l);
				ft_hexalow(va_arg(past, unsigned long), &l);
			}
			else if (print[j] == 'u')
				ft_putnbr(va_arg(past, unsigned int));
		}
		else
		{
			ft_putchar(print[j]);
			l++;
		}
		j++;
	}
	va_end(past);
	return (l);
}

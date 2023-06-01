/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:35:53 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/06/01 17:47:58 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_specifier(char spec, va_list past, int *l)
{
	if (spec == 'c')
		ft_putchar(va_arg(past, int));
	else if (spec == '%')
		ft_putchar('%');
	else if (spec == 's')
		ft_putstr(va_arg(past, char *), l);
	else if (spec == 'd' || spec == 'i')
		ft_putnbr(va_arg(past, int));
	else if (spec == 'x')
		ft_hexalow(va_arg(past, unsigned int), l);
	else if (spec == 'X')
		ft_hexaup(va_arg(past, unsigned int), l);
	else if (spec == 'p')
	{
		ft_putstr("0x", l);
		ft_hexalow(va_arg(past, unsigned long), l);
	}
}

int	ft_printf(const char *print, ...)
{
	int		j;
	int		l;
	va_list	past;

	l = 0;
	j = 0;
	va_start(past, print);
	while (print[j])
	{
		if (print[j] == '%')
		{
			j++;
			handle_specifier(print[j], past, &l);
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

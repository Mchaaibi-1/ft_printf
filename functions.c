/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:50:00 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/06/03 17:19:12 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char a)
{
	write (1, &a, 1);
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

void	ft_putstr(char *s, int *l)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		(*l) += 6;
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		(*l)++;
		i++;
	}
}

void	ft_hexalow(unsigned long d, int *l)
{
	int		i;
	int		j;
	int		modulo;
	char	hexa[17];

	i = 0;
	if (d == 0)
		ft_putchar(48);
	while (d != 0)
	{
		modulo = d % 16;
		if (modulo < 10)
			hexa[i++] = modulo + 48;
		else
			hexa[i++] = modulo + 87;
		d /= 16;
	}
	j = i - 1;
	while (j >= 0)
	{
		ft_putchar(hexa[j]);
		(*l)++;
		j--;
	}
}

void	ft_hexaup(unsigned int d, int *l)
{
	char	hexa[17];
	int		i;
	int		modulo;
	int		j;

	i = 0;
	while (d != 0)
	{
		modulo = d % 16;
		if (modulo < 10)
			hexa[i++] = modulo + 48;
		else
			hexa[i++] = modulo + 55;
		d /= 16;
	}
	j = i - 1;
	while (j >= 0)
	{
		ft_putchar(hexa[j]);
		(*l)++;
		j--;
	}
}

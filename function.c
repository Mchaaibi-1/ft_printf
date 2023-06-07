/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:47:50 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/06/07 13:58:18 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsignedecimal(unsigned int x, int *l)
{
	char	buffer[50];
	int		i;
	int		j;

	i = 0;
	if (x == 0)
		ft_putchar(48, l);
	while (x > 0)
	{
		buffer[i++] = x % 10 + '0';
		x /= 10;
	}
	j = i -1;
	while (j >= 0)
	{
		ft_putchar(buffer[j--], l);
	}
}

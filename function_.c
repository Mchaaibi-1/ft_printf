/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:55:39 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/06/01 16:55:49 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	unsignedecimal(unsigned int x)
{
	char	buffer[50];
	int		i;
	int		j;

	i = 0;
	while (x > 0)
	{
		buffer[i++] = x % 10 + '0';
		x /= 10;
	}
	j = i -1;
	while (j >= 0)
	{
		ft_putchar(buffer[j--]);
	}
}

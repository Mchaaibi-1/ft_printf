/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:50:00 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/05/01 14:56:58 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char a)
{
    write (1, &a, 1);
}

void ft_putnbr(int n)
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

void ft_putstr(char *s, int *l)
{
    int i;

    i = 0;
    if(!s)
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

void ft_hexalow(unsigned long d, int *l)
{
    char hexa[17]; 
    int i = 0;
    if (d == 0)
        ft_putchar(48);
    while (d != 0)
    {
        int modulo = d % 16;

        if (modulo < 10)
        {
            hexa[i++] = modulo + 48;
        }
        else
        {
            hexa[i++] = modulo + 87;
        }
        d /= 16;
    }
    int j = i - 1;
    while (j >= 0)
    {
        ft_putchar(hexa[j]);
        (*l)++;
        j--;
    }
}

void ft_hexaup(unsigned int d, int *l)
{
    char hexa[17]; 
    int i = 0;
    while (d != 0)
    {
        int modulo = d % 16;

        if (modulo < 10)
        {
            hexa[i++] = modulo + 48;
        }
        else
        {
            hexa[i++] = modulo + 55;
        }
        d /= 16;
    }
    int j = i - 1;
    while (j >= 0)
    {
        ft_putchar(hexa[j]);
        (*l)++;
        j--;
    }
}

void unsignedecimal(unsigned int x)
{
    char buffer[50];
    int i;
    i = 0;
    while(x > 0)
    {
        buffer[i++] = x % 10 + '0';
        x /= 10;
    }
    int j;
    j = i -1;
    while (j >= 0)
    {
        ft_putchar(buffer[j--]);
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:36:57 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/13 14:57:16 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_write(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_flags(va_list args, char flag)
{
	if (flag == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (flag == 'c')
		return (ft_write(va_arg(args, int)));
	if (flag == 'd')
		return (ft_putnbr(va_arg(args, int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_flags(args, str[i + 1]);
			i += 2;
		}
		else
		{
			write(1, &(str[i]), 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}

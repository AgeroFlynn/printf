/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbernard <wbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:09:11 by wbernard          #+#    #+#             */
/*   Updated: 2022/01/15 00:28:25 by wbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str++)
		;
	return (str - s - 1);
}

int	ft_put_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_put_str(char *str)
{
	char	*s;

	s = str;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
		write(1, s++, 1);
	return (ft_strlen(str));
}

int	ft_putnbr_base(size_t number, int size, char *base)
{
	if (number < (size_t) size)
		return (write(1, &base[number], 1));
	else
		return (ft_putnbr_base(number / size, size, base)
			+ ft_putnbr_base(number % size, size, base));
}

int	ft_putnbr_base_for_integer(int number, int size, char *base)
{
	if (number < 0)
		return (write(1, "-", 1)
			+ ft_putnbr_base((unsigned int)(number * -1), size, base));
	return (ft_putnbr_base((unsigned int) number, size, base));
}

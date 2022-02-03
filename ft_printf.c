/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbernard <wbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:14:07 by wbernard          #+#    #+#             */
/*   Updated: 2022/01/15 00:48:51 by wbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversations(char c, va_list argptr)
{
	if (c == 'c')
		return (ft_put_char(va_arg(argptr, int)));
	if (c == 's')
		return (ft_put_str(va_arg(argptr, char *)));
	if (c == 'p')
		return (write(1, "0x", 2) + ft_putnbr_base(va_arg(argptr, unsigned long)
				, 16, "0123456789abcdef"));
	if (c == 'd')
		return (ft_putnbr_base_for_integer(va_arg(argptr, int),
				10, "0123456789"));
	if (c == 'i')
		return (ft_putnbr_base_for_integer(va_arg(argptr, int),
				10, "0123456789"));
	if (c == 'u')
		return (ft_putnbr_base(va_arg(argptr, unsigned int),
				10, "0123456789"));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(argptr, unsigned int)
				, 16, "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(argptr, unsigned int)
				, 16, "0123456789ABCDEF"));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char	*format, ...)
{
	va_list		argptr;
	const char	*iterator;
	int			result;

	va_start(argptr, format);
	iterator = format;
	result = 0;
	while (*iterator)
	{
		if (*iterator == '%')
		{
			iterator++;
			result += ft_conversations(*iterator, argptr);
		}
		else
			result += write(1, iterator, 1);
		iterator++;
	}
	va_end(argptr);
	return (result);
}

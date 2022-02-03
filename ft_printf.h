/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbernard <wbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:22:54 by wbernard          #+#    #+#             */
/*   Updated: 2022/01/15 00:48:54 by wbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_put_char(int c);

int		ft_put_str(char *str);

int		ft_putnbr_base(size_t number, int size, char *base);

int		ft_putnbr_base_for_integer(int number, int size, char *base);

size_t	ft_strlen(const char *str);

int		ft_conversations(char c, va_list argptr);

int		ft_printf(const char *format, ...);

#endif

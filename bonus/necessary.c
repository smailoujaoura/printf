/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   necessary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:25:59 by soujaour          #+#    #+#             */
/*   Updated: 2024/11/06 21:41:49 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_both_directions(int pad) //int space_or_zero
{
	while (pad-- > 0)
		ft_putchar_fd(' ', 1);
}

void print_string(char *str, t_flags flags)
{
	int	len = ft_strlen(str, 1);
	if (flags.precision > len)
		flags.precision = len;
	int real;
	if (len > flags.precision && flags.point)
		real = flags.precision;
	else
		real = len;
	int	pad = flags.width - real;
	if (flags.width)
	{
		if (!flags.minus)
		{
			pad_both_directions(pad);
			ft_putstr_len(str, real);
		}
		else if (flags.minus)
		{	
			ft_putstr_len(str, real);
			pad_both_directions(pad);
		}
	}
	else
	{
		if (flags.point)
			ft_putstr_len(str, flags.precision);
		else
			ft_putstr_fd(str, 1);
		while (flags.width - len > 0)
		{
			if (flags.zero == 1)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			flags.width--;
		}
	}
}

void print_integer(int i, t_flags flags)
{
	int len;
	long	num = i;

	len = integer_len(i);
	if (flags.minus)
	{
		while (flags.precision - len && flags.point)
			ft_putchar_fd('0', 1), flags.precision--;
		if (flags.plus)
			ft_putchar_fd('+', 1);
		else if (flags.space)
			ft_putchar_fd(' ', 1);
		ft_putnbr_fd(i, 1);
		handle_trailing_padding(flags, len);
	}
	else if((flags.space || flags.point || flags.zero) && (flags.width > len || flags.precision > len))
		(handle_leading_padding(flags, len, &num), ft_putnbr_fd(num, 1));
	else
	{
		if (flags.point == 1 && flags.precision == 0 && i == 0)
			return ;
		while (len < flags.width - flags.plus - flags.space)
			(ft_putchar_fd(' ', 1), flags.width--);
		if (flags.plus)
			ft_putchar_fd('+', 1);
		else if (flags.space && len < flags.width - flags.plus - flags.space)
			(ft_putchar_fd(' ', 1), flags.space = 0);
		ft_putnbr_fd(i, 1);
	}
}

void print_char(char c, t_flags flags)
{
	if (flags.minus)
	{
		ft_putchar_fd(c, 1);
		while (flags.width - 1 > 0)
		{
			ft_putchar_fd(' ', 1);
			flags.width--;
		}
	}
	else if (flags.width || flags.width)
	{
		while (flags.width - 1 > 0)
		{
			if (flags.zero && !flags.minus)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			flags.width--;
		}		
	}
	if (!flags.minus)
		ft_putchar_fd(c, 1);
}

void print_hex(unsigned int i, char cases, t_flags flags)
{
	int	len;

	len = hex_len(i);
	if (flags.minus)
	{
		if (cases == 'X' && flags.hash)
			ft_putstr_fd("0X", 1);
		if (cases == 'x' && flags.hash)
			ft_putstr_fd("0x", 1);
		write_hex(i, cases);
		handle_trailing_padding(flags, len);
	}
	else if((flags.space || flags.point || flags.zero) && (flags.width > len))
		(handle_leading_padding(flags, len, (long *)&i), write_hex(i, cases));
	else
	{
		while (len < flags.width - flags.plus - flags.space)
			ft_putchar_fd(' ', 1);
		if (cases == 'X' && flags.hash)
			ft_putstr_fd("0X", 1);
		if (cases == 'x' && flags.hash)
			ft_putstr_fd("0x", 1);
		write_hex(i, cases);
	}
}

void print_unsinged(unsigned int ui)
{
	if (ui < 10)
		ft_putchar_fd(ui % 10 + '0', 1);
	else
	{
		print_unsinged(ui / 10);
		print_unsinged(ui % 10);
	}
}

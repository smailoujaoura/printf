/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:27:04 by soujaour          #+#    #+#             */
/*   Updated: 2024/11/15 21:24:36 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void loop_over_specifiers(va_list args, char format_specifier, t_flags flags)
{
	if (format_specifier == 'c')
		print_char(va_arg(args, int), flags);
	else if (format_specifier == 's')
		print_string(va_arg(args, char *), flags);
	else if (format_specifier == 'i' || format_specifier == 'd')
		print_integer(va_arg(args, int), flags);
	else if (format_specifier == 'p')
		print_pointer(va_arg(args, void *), flags);
	else if (format_specifier == 'u')
		print_unsinged(va_arg(args, unsigned int));
	else if (format_specifier == 'x' || format_specifier == 'X')
		print_hex(va_arg(args, unsigned int), format_specifier, flags);
	else if (format_specifier == '%')
		print_char('%', flags);
}

static char is_specifier(char c)
{
	char *format_specifiers;
	int i;

	i = 0;
	format_specifiers = "cspdiuxX%";
	while (format_specifiers[i])
	{
		if (c == format_specifiers[i])
			return (format_specifiers[i]);
		i++;
	}
	return (0);
}

void	count_width_zero(char c, t_flags *flags, int *booleana)
{
	if (c == '0' && *booleana)
		(*flags).zero = 1;
	if ((c >= '0' && c <= '9') && (*flags).point)
	{
		(*flags).precision *= 10;
		(*flags).precision += (c - '0');
		*booleana = 0;
	}
	//else if ((c >= '0' && c <= '9') && (*flags).minus)
	//{
	//	(*flags).padding *= 10;
	//	(*flags).padding += (c - '0');
	//	*booleana = 0;
	//}
	else
	{
		(*flags).width *= 10;
		(*flags).width += (c - '0');
		*booleana = 0;
	}
}

static int get_specifier(const char *str, int *i, char sp, t_flags *flags)
{
	int booleana;
	
	booleana = 1;
	(*i)++;
	while (str[*i] == ' ' || str[*i] == '+' || str[*i] == '#' || 
		str[*i] == '0' || (str[*i] >= '0' && str[*i] <= '9') || str[*i] == '-' || str[*i] == '.')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			count_width_zero(str[*i], flags, &booleana);
		if (str[*i] == '+')
			(*flags).plus = 1;
		if (str[*i] == ' ')
			(*flags).space = 1;
		if (str[*i] == '#')
			(*flags).hash = 1;
		if (str[*i] == '-')
			(*flags).minus = 1;
		if (str[*i] == '.')
			(*flags).point = 1;
		(*i)++;
	}
	sp = is_specifier(str[*i]);
	return (sp);
}

static void parse_formated_string(const char *str, va_list args)
{
	char	specifier;
	int		i;
	t_flags	flags;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_memset(&flags, 0, sizeof(flags));
			specifier = 0;
			specifier = get_specifier((char *)str, &i, specifier, &flags);
			if (specifier)
			{
				loop_over_specifiers(args, specifier, flags);
				i++;
			}
		}
		else
			ft_putchar_fd(str[i++], 1);
	}
}

int ft_printf(const char *formated_string, ...)
{
	va_list args;

	if (write(1, NULL, 0) == -1)
		return (-1);
	count_printed_chars(-1);
	va_start(args, formated_string);
	parse_formated_string(formated_string, args);
	va_end(args);
	return (count_printed_chars(0));
}

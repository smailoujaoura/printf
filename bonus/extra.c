/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:36:19 by soujaour          #+#    #+#             */
/*   Updated: 2024/11/15 19:47:47 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len_long(unsigned long z)
{
	int	len;

	len = 0;
	while (z != 0)
	{
		len++;
		z /= 16;
	}
	return (len);
}

//void	prepare_array(char *arr, t_flags flags)
//{
//	while (*arr != '0' && *(arr + 1) != 'x')
//		arr++;
//	print_string(arr, flags);
//}

void	print_pointer(void *ptr, t_flags flags)
{
	int				i;
	int				digit;
	unsigned long	z;
	char			hex_digits[19];

	z = (unsigned long)ptr;
	if (z == 0)
	{
		print_string("0x0", flags);
		return ;
	}
	i = hex_len_long(z) + 2;
	hex_digits[i--] = '\0';
	while (z != 0)
	{
		digit = z & 0x0F;
		hex_digits[i] = "0123456789abcdef"[digit];
		z >>= 4;
		i--;
	}
	hex_digits[i--] = 'x';
	hex_digits[i--] = '0';
	print_string(hex_digits, flags);
	//prepare_array(hex_digits + i, flags);
}

void	write_hex(unsigned int ui, char cases)
{
	char	*hex;

	if (cases == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (ui >= 16)
		write_hex(ui / 16, cases);
	ft_putchar_fd(hex[ui % 16], 1);
}

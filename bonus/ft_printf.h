/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soujaour <soujaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:28:04 by soujaour          #+#    #+#             */
/*   Updated: 2024/11/16 09:08:24 by soujaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_flags
{
	int hash;
	int plus;
	int space;
	int point;
	int zero;
	int minus;
	int width;
	int precision;
	int sign;
	int sign_two;
	//int	padding;
}	t_flags;


#include <limits.h>
// flag '.' : -with 's' > precision prints that many chars

//	+
//	#
//	' '
//	0
//	n
//	-
//	.

int		ft_printf(const char *formated_string, ...);
int		count_printed_chars(int start);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long n, int fd);
void	write_hex(unsigned int ui, char cases);
void	print_string(char *str, t_flags flags);
void	print_integer(int i, t_flags flags);
void	print_char(char c, t_flags flags);
void	print_pointer(void *ptr, t_flags flags);
void	print_unsinged(unsigned int ui);
void	print_hex(unsigned int i, char cases, t_flags flag);

int	ft_atoi(const char *str);
char	*ft_itoa(int n);
void	handle_leading_padding(t_flags flags, int len, long *i);
void	handle_trailing_padding(t_flags flags, int len);
int	hex_len(unsigned int i);
int integer_len(int i);

void	*ft_memset(void *b, int c, size_t len);
int	ft_strlen(const char *s, int purpose);
void	ft_putstr_len(char *str, int width);


#endif
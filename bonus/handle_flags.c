#include "ft_printf.h"

int	sign_of_number(long *i, int precision, int len, t_flags *flags)
{
	if (*i < 0)
	{
		(*flags).sign = 1;
		(*flags).sign_two = 1;
		*i *= -1;
	}
	if ((*flags).sign && precision >= len)
		return (1);
	return (0);
}

void	handle_sign(t_flags *flags, int pad_width)
{
	if ((*flags).sign && (pad_width < 0 || (*flags).zero))
	{
		ft_putchar_fd('-', 1);
		(*flags).sign = 0;
	}
}

void	handle_leading_padding(t_flags flags, int len, long *i)
{
	int real = 0;
	if (len < flags.precision)
		real = flags.precision;
	else
		real = len;
	int pad_width = flags.width - real - sign_of_number(i, flags.precision, len, &flags);
	handle_sign(&flags, pad_width);
	while(pad_width-- > 0)
	{
		if (flags.zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	handle_sign(&flags, pad_width);
	//if (flags.plus)
	//		ft_putchar_fd('+', 1);
	//else if (flags.space)
	//		ft_putchar_fd(' ', 1);
	//int pad_preci = flags.precision - len;
	while(flags.precision > len - flags.sign_two)
	{
		if (flags.space && !flags.sign_two)
			(ft_putchar_fd(' ', 1), flags.space = 0);
		if (flags.zero || flags.point)
			ft_putchar_fd('0', 1);
		flags.precision--;
	}
}

void	handle_trailing_padding(t_flags flags, int len)
{
	while (flags.width > len + flags.precision + 1)
	{
		ft_putchar_fd(' ', 1);
		flags.width--;
	}
}

int	hex_len(unsigned int i)
{
	int	len;

	len = 0;
	while (i != 0)
	{
		i /= 16;
		len++;
	}
	return (len);
}

int integer_len(int i)
{
	int	len;

	len = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		len++;
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

int	ft_strlen(const char *s, int purpose)
{
	int	len;

	len = 0;
	if (!s && purpose)
		return (6);
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

void	ft_putstr_len(char *str, int width)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str && str[i] && i < width)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}
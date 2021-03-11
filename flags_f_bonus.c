#include "ft_printf.h"

static int	int_length(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static int	is_negative(double input)
{
	return (*((unsigned long *)(&input)) & 0x8000000000000000 ? 1 : 0);
}

static void	putfloat(double input, int dec_len)
{
	if (is_negative(input) && input > -1)
		ft_putchar('-');
	ft_putnbr(input);
	if (dec_len)
		ft_putchar('.');
	ft_putdecimal(input, dec_len);
}

static void	bigger_width(double input, int len, int dec_len, t_flagstruct flags)
{
	int	filler;

	filler = flags.width - len;
	if (is_negative(input) && input > -1)
		filler--;
	if (flags.left_aligned)
	{
		putfloat(input, dec_len);
		print_space(filler);
	}
	else if (flags.zeroes)
	{
		if (is_negative(input))
		{
			ft_putchar('-');
			input = input * -1;
		}
		print_padding(filler, input);
		putfloat(input, dec_len);
	}
	else
	{
		print_space(filler);
		putfloat(input, dec_len);
	}
}

static double	decimal_rounding(double input, int dec_len)
{
	int	i;
	long long	nb;
	long double	copy;
	double	to_add;

	i = 0;
	copy = input;
	while (i < dec_len)
	{
		copy = copy * 10;
		i++;
	}
	nb = copy;
	if ((copy - nb) >= 0.5 || (copy - nb) <= -0.5)
	{
		if (((copy - nb == 0.5) || (copy - nb == -0.5)) && (nb % 2 == 0))
			return (input);
		to_add = 0.55;
		while (i > 0)
		{
			to_add = to_add / 10;
			i--;
		}
		if (input < 0)
			input = input - to_add;
		else
			input = input + to_add;
	}
	return (input);
}

void	flags_f(double input, t_flagstruct flags)
{
	int	len;
	int	dec_len;

	dec_len = 6;
	if (flags.precision >= 0)
		dec_len = flags.precision;
	input = decimal_rounding(input, dec_len);
	len = int_length(input) + dec_len;
	if (dec_len)
		len ++;
	if (len >= flags.width)
		putfloat(input, dec_len);
	if (flags.width > len)
		bigger_width(input, len, dec_len, flags);
}
#include "ft_printf.h"



void	ft_putdecimal(long double decimal, int dec_len)
{
	int	i;
	int	nb;

	i = 0;
	if (decimal < 0)
		decimal = decimal * -1;
	nb = decimal;
	decimal = decimal - nb;
	while (i < dec_len )
	{
		decimal = decimal * 10;
		nb = decimal;
		ft_putchar(nb + '0');
		decimal = decimal - nb;
		i++;
	}
}
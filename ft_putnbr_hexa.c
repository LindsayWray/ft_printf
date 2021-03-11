/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 09:46:39 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:40:57 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned long input, char *base)
{
	int	remainder;

	if (input / 16 > 0)
	{
		ft_putnbr_hexa((input / 16), base);
	}
	remainder = input % 16;
	ft_putchar(base[remainder]);
}

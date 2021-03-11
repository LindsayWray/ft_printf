/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_uns.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 09:45:42 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:41:08 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_uns(unsigned int nb)
{
	if (nb / 10 != 0)
		ft_putnbr_uns(nb / 10);
	ft_putchar(nb % 10 + '0');
}

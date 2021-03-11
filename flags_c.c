/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_c.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:38:36 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:38:38 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void 	flags_c(int input, t_flagstruct flags)
{
	int	len;
	int	filler;

	len = 1;
	if (flags.width == 0 || flags.width == 1)
		ft_putchar(input);
	if (flags.width > len)
	{
		filler = flags.width - len;
		if (flags.left_aligned)
		{
			ft_putchar(input);
			print_space(filler);
		}
		else if (flags.zeroes)
		{
			input = print_padding(filler, input);
			ft_putchar(input);
		}
		else
		{
			print_space(filler);
			ft_putchar(input);
		}
	}
}

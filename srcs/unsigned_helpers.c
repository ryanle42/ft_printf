/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:53:52 by rle               #+#    #+#             */
/*   Updated: 2017/04/05 15:17:52 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unsigned_int_length(uintmax_t n)
{
	int i;

	i = 1;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	unsigned_flags(t_param *params)
{
	if (params->flags->zero && params->flags->minus)
		params->flags->zero = 0;
	if (params->flags->zero && params->is_precision)
		params->flags->zero = 0;
	if (params->flags->plus && params->flags->space)
		params->flags->space = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:38:54 by rle               #+#    #+#             */
/*   Updated: 2016/12/05 19:15:34 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*itoa_two(intmax_t n, int i, int rev)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * ft_int_length(n) + 1)))
		return (NULL);
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
	return rev ? (ft_strrev(str, i)) : str;
}

char			*ft_itoa(intmax_t n, int precision, int param, int rev)
{
	char		*str;
	int 		i;
	int 		flag;
	int  		zeros;

	flag = 0;
	if (n < 0)
	{
		flag++;
		n = -n;
	}
	zeros = precision - ft_int_length(n);
	if (param)
		zeros -= flag;
	if (zeros < 0)
		zeros = 0;
	if (!(str = (char *)malloc(sizeof(char) * zeros + flag + 1)))
		return (NULL);
	i = 0;
	if (flag)
		str[i++] = '-';
	while (i < zeros + flag)
		str[i++] = '0';
	str[i] = '\0';
	return (ft_strjoin(str, itoa_two(n, 0, rev)));
}

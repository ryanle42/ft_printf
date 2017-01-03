/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copystr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 16:34:40 by rle               #+#    #+#             */
/*   Updated: 2016/12/27 15:20:05 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copystr(char *str)
{
	char	*copy;
	int		i;
	int		len;

	len = ft_strlen(str);
	copy = ft_strnew(len);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}

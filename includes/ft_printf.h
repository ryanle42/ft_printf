/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:50:27 by rle               #+#    #+#             */
/*   Updated: 2017/04/05 15:26:02 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <stdint.h>

typedef struct	s_flags
{
	int			plus;
	int			minus;
	int			zero;
	int			hash;
	int			space;
}				t_flag;

typedef struct	s_parameters{
	t_flag		*flags;
	int			size;
	int			width;
	int			precision;
	int			is_precision;
	int			counter;
	int			zeros;
}				t_param;

int				get_size(const char *fmt);
void			remove_conflict_flags(t_param *params);
int				get_flags(int fmt, t_flag *flags);
t_param			*reset_params(void);
void			get_params(const char **fmt, t_param *params);
intmax_t		convert_signed(t_param *params, intmax_t n);
intmax_t		convert_unsigned(t_param *params, uintmax_t n);
void			write_int(t_param *params, intmax_t n);
void			int_flags(t_param *params);
void			int_add_prefixes(char *str, int *i, t_param *params, int flag);
void			write_unsigned_int(t_param *params, uintmax_t n);
void			unsigned_flags(t_param *params);
int				unsigned_int_length(uintmax_t n);
void			write_octal(t_param *params, uintmax_t n);
int				oct_length(uintmax_t n);
char			*make_octal(uintmax_t n, t_param *params);
void			write_hex(t_param *params, uintmax_t n, int letters);
void			write_ptr(t_param *params, long int n);
void			hash_except(t_param *params, int letters);
int				hex_length(uintmax_t n);
void			write_char(t_param *params, unsigned char c);
void			write_string(t_param *params, char *str);
int				ft_printf(const char *fmt, ...);

#endif

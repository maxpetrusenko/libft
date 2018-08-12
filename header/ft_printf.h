/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:25:26 by mpetruse          #+#    #+#             */
/*   Updated: 2018/08/01 09:04:22 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <wchar.h>

typedef struct		s_flags
{
	int				minus;
	int				plus;
	int				space;
	int				hashtag;
	int				zero;
}					t_flags;

typedef struct		s_param
{
	int				dot;
	char			specifier;
	t_flags			flags;
	int				width;
	int				precision;
	char			*length;
	int				l;
}					t_param;

typedef char		*(*t_func)(t_param*, va_list*);

char				*ft_handle_wstr(t_param *args, va_list *ap);
char				*ft_handle_binary(t_param *args, va_list *ap);
char				*ft_handle_addr(t_param *args, va_list *ap);
char				*ft_handle_hex(t_param *args, va_list *ap);
char				*ft_handle_char(t_param *args, va_list *ap);
char				*ft_handle_octal(t_param *args, va_list *ap);
char				*ft_handle_uint(t_param *args, va_list *ap);
char				*ft_handle_str(t_param *args, va_list *ap);
char				*ft_handle_int(t_param *args, va_list *ap);
size_t				ft_wstrlen(unsigned *s);
int					ft_algo(t_param *args, va_list *ap);
t_func				get_func(char c);
char				*parse_length(char *fmt, size_t *i);
int					parse_precision(char *fmt, size_t *i, va_list *ap,
					t_param *spec);
int					parse_width(char *fmt, size_t *i, va_list *ap,
					t_param *spec);
t_flags				parse_flags(char *fmt, size_t *i);
t_param				*parse_params(char *ftm, va_list *ap, size_t *i);
int					ft_printf(char *fmt, ...);
size_t				size_of_final_str(char *fmt, va_list *ap);
long long			convert(t_param *arg, va_list *ap);
unsigned long long	convert_u(t_param *arg, va_list *ap);
size_t				ft_wcslen(const wchar_t *s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:17:02 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/25 13:52:22 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_algo(t_param *arg, va_list *ap)
{
	char		*value;
	t_func		f;
	int			res;

	f = get_func(arg->specifier);
	if (f)
		value = f(arg, ap);
	else if (arg->width != 0)
	{
		arg->l = arg->width;
		value = ft_strnew(arg->width);
		ft_memset(value, ' ', arg->width);
		res = (arg->flags.minus) ? 0 : arg->width - 1;
		ft_memset(value + res, arg->specifier, 1);
	}
	else
	{
		arg->l = 1;
		value = ft_strnew(1);
		ft_memset(value, arg->specifier, 1);
	}
	res = write(1, value, arg->l);
	ft_memdel((void **)&value);
	return (res);
}

static void		init_funcs(t_func *funcs)
{
	funcs['x'] = &ft_handle_hex;
	funcs['X'] = &ft_handle_hex;
	funcs['s'] = &ft_handle_str;
	funcs['S'] = &ft_handle_wstr;
	funcs['i'] = &ft_handle_int;
	funcs['d'] = &ft_handle_int;
	funcs['D'] = &ft_handle_int;
	funcs['o'] = &ft_handle_octal;
	funcs['O'] = &ft_handle_octal;
	funcs['%'] = &ft_handle_char;
	funcs['c'] = &ft_handle_char;
	funcs['C'] = &ft_handle_char;
	funcs['p'] = &ft_handle_addr;
	funcs['b'] = &ft_handle_binary;
	funcs['U'] = &ft_handle_uint;
	funcs['u'] = &ft_handle_uint;
}

t_func			get_func(char c)
{
	static t_func	*funcs;
	int				n;

	if (!funcs)
	{
		funcs = ft_memalloc(sizeof(*funcs) * 256);
		if (funcs)
			init_funcs(funcs);
	}
	n = (int)c;
	return (funcs[n]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:58:21 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/25 13:51:40 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	del_mem(t_param *args)
{
	if (!args)
		return ;
	ft_strdel(&(args->length));
	ft_memdel((void **)&args);
}

t_param	*parse_params(char *fmt, va_list *ap, size_t *i)
{
	t_param *res;

	res = malloc(sizeof(t_param));
	ft_bzero(res, sizeof(t_param));
	res->flags = parse_flags(fmt, i);
	res->width = parse_width(fmt, i, ap, res);
	res->precision = parse_precision(fmt, i, ap, res);
	res->length = parse_length(fmt, i);
	res->specifier = fmt[(*i)];
	return (res);
}

size_t	size_of_final_str(char *fmt, va_list *ap)
{
	t_param *param;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			param = parse_params((char*)fmt, ap, &i);
			size = size + ft_algo(param, ap);
			del_mem(param);
		}
		else
		{
			write(1, (fmt + i), 1);
			size++;
		}
		i++;
	}
	return (size);
}

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, fmt);
	size = (int)size_of_final_str(fmt, &ap);
	va_end(ap);
	return (size);
}

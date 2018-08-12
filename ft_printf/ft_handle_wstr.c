/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:17:17 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/25 13:44:35 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_width(t_param *args)
{
	int		num;
	char	*str;

	if (args->precision > 0 && args->precision < args->l)
		num = args->width - args->precision;
	else
		num = args->width - args->l;
	num = (num < 0) ? 0 : num;
	str = ft_strnew(num);
	ft_memset(str, ' ', num);
	return (str);
}

static char	*get_precision(t_param *args, wchar_t *buff)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strnew(args->l);
	while (*((unsigned *)buff) != L'\0')
	{
		temp[i] = *buff;
		buff++;
		i++;
	}
	if (args->precision > 0 && args->precision < args->l)
		str = ft_strsub(temp, 0, args->precision);
	else
		str = ft_strsub(temp, 0, args->l);
	free(temp);
	return (str);
}

char		*ft_handle_wstr(t_param *args, va_list *ap)
{
	char	*res;
	char	*value_to_print;
	char	*prefix_postfix;
	wchar_t	*buff;

	buff = va_arg(*ap, wchar_t*);
	args->l = (int)(ft_wstrlen((unsigned *)buff));
	value_to_print = get_precision(args, buff);
	prefix_postfix = get_width(args);
	if (args->flags.minus)
		res = ft_strjoin(value_to_print, prefix_postfix);
	else
		res = ft_strjoin(prefix_postfix, value_to_print);
	args->l = ft_strlen(res);
	return (res);
}

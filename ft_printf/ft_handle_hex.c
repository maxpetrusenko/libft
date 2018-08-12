/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:42:30 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/25 12:41:03 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_digits(unsigned long long n)
{
	int					i;
	unsigned long long	temp;

	temp = n;
	i = 1;
	while (temp > 9)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

static void		add_ox(t_param *args, char **value, char **prefix,
unsigned long long n)
{
	if (args->flags.hashtag && n != 0)
	{
		if (!args->dot && !args->flags.minus && args->flags.zero)
		{
			if (args->specifier == 'x')
				*prefix = ft_strjoin(ft_strsub("0x", 0, 2), *prefix);
			else
				*prefix = ft_strjoin(ft_strsub("0X", 0, 2), *prefix);
		}
		else
		{
			if (args->specifier == 'x')
				*value = ft_strjoin(ft_strsub("0x", 0, 2), *value);
			else
				*value = ft_strjoin(ft_strsub("0X", 0, 2), *value);
		}
	}
	return ;
}

static char		*get_precision(t_param *args, unsigned long long n)
{
	char	*temp;
	char	*res;
	char	*start_of_res;
	int		dig_to_print;
	int		num_of_dig;

	num_of_dig = count_digits(n);
	temp = ft_itoa_base_for_uint(n, 16, args->specifier);
	num_of_dig = ft_strlen(temp);
	dig_to_print = args->precision > num_of_dig ? args->precision : num_of_dig;
	res = ft_strnew(dig_to_print + 1);
	ft_bzero(res, dig_to_print + 1);
	start_of_res = res;
	while (args->precision > num_of_dig++)
		*(res++) = '0';
	if (n == 0 && args->dot)
		temp = ft_strsub("", 0, 0);
	ft_strcpy(res, temp);
	ft_memdel((void **)&temp);
	args->l = ft_strlen(start_of_res);
	return (start_of_res);
}

static char		*get_width(t_param *args)
{
	char	*res;
	char	*start_of_res;
	int		sym_to_print;
	char	zero_or_space;

	zero_or_space = ' ';
	if (args->flags.hashtag)
		args->l = args->l + 2;
	if (!args->dot && !args->flags.minus && args->flags.zero)
		zero_or_space = '0';
	sym_to_print = args->width > args->l ? args->width : 0;
	res = ft_strnew(sym_to_print + 1);
	start_of_res = res;
	if (sym_to_print)
		while (sym_to_print > args->l++)
			*(res++) = zero_or_space;
	return (start_of_res);
}

char			*ft_handle_hex(t_param *args, va_list *ap)
{
	char					*res;
	char					*value_to_print;
	char					*prefix_postfix;
	unsigned long long int	n;

	n = convert_u(args, ap);
	args->l = count_digits(n);
	value_to_print = get_precision(args, n);
	prefix_postfix = get_width(args);
	add_ox(args, &value_to_print, &prefix_postfix, n);
	if (args->flags.minus)
		res = ft_strjoin(value_to_print, prefix_postfix);
	else
		res = ft_strjoin(prefix_postfix, value_to_print);
	args->l = ft_strlen(res);
	return (res);
}

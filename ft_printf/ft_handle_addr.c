/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 19:11:59 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/25 13:50:30 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_digits(long long n)
{
	int			i;
	long long	temp;

	temp = n;
	i = 1;
	if (temp < 0)
		temp = -temp;
	while (temp > 9)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

static void		add_ox(t_param *args, char **value, char **prefix)
{
	if (!args->dot && !args->flags.minus && args->flags.zero)
		*prefix = ft_strjoin(ft_strsub("0x", 0, 2), *prefix);
	else
		*value = ft_strjoin(ft_strsub("0x", 0, 2), *value);
	return ;
}

static char		*get_precision(t_param *args, long long n)
{
	char		*temp;
	char		*res;
	char		*start_of_res;
	int			dig_to_print;
	int			num_of_dig;

	num_of_dig = count_digits(n);
	temp = ft_itoa_base_for_uint(n, 16, 'x');
	if (n == 0 && args->dot)
		temp = ft_strnew(0);
	num_of_dig = ft_strlen(temp);
	dig_to_print = args->precision > num_of_dig ? args->precision : num_of_dig;
	res = ft_strnew(dig_to_print + 1);
	start_of_res = res;
	while (args->precision > num_of_dig++)
		*(res++) = '0';
	if (n < 0)
		n = -n;
	ft_strcpy(res, temp);
	args->l = ft_strlen(start_of_res) + 2;
	ft_memdel((void **)&temp);
	return (start_of_res);
}

static char		*get_width(t_param *args)
{
	char		*res;
	char		*start_of_res;
	int			sym_to_print;
	int			check_for_zero;
	char		zero_or_space;

	check_for_zero = 0;
	if (!args->dot && !args->flags.minus && args->flags.zero)
		check_for_zero = 1;
	sym_to_print = args->width > args->l ? args->width : 0;
	res = ft_strnew(sym_to_print + 1);
	start_of_res = res;
	zero_or_space = (check_for_zero ? '0' : ' ');
	if (sym_to_print)
		while (sym_to_print > args->l++)
			*(res++) = zero_or_space;
	return (start_of_res);
}

char			*ft_handle_addr(t_param *args, va_list *ap)
{
	char				*res;
	char				*value_to_print;
	char				*prefix_postfix;
	unsigned long long	n;
	void				*ptr;

	ptr = va_arg(*ap, void*);
	n = (unsigned long long)ptr;
	args->l = count_digits(n);
	value_to_print = get_precision(args, n);
	prefix_postfix = get_width(args);
	add_ox(args, &value_to_print, &prefix_postfix);
	if (args->flags.minus)
		res = ft_strjoin(value_to_print, prefix_postfix);
	else
		res = ft_strjoin(prefix_postfix, value_to_print);
	args->l = ft_strlen(res);
	return (res);
}

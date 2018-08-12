/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:43:35 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/24 20:43:45 by mpetruse         ###   ########.fr       */
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

static char		*get_precision(t_param *args, unsigned long long n)
{
	char	*temp;
	char	*res;
	char	*start_of_res;
	int		dig_to_print;
	int		num_of_dig;

	num_of_dig = count_digits(n);
	dig_to_print = args->precision > num_of_dig ? args->precision : num_of_dig;
	res = ft_strnew(dig_to_print + 1);
	ft_bzero(res, dig_to_print + 1);
	start_of_res = res;
	while (args->precision > num_of_dig++)
		*(res++) = '0';
	temp = ft_itoaf(n);
	if (n == 0 && args->dot)
		temp = ft_strsub("", 0, 0);
	ft_strcpy(res, temp);
	args->l = ft_strlen(start_of_res);
	free(temp);
	return (start_of_res);
}

static char		*get_width(t_param *args)
{
	char	*res;
	char	*start_of_res;
	int		sym_to_print;
	int		check_for_zero;
	char	zero_or_space;

	check_for_zero = 0;
	if (!args->dot && !args->flags.minus && args->flags.zero)
		check_for_zero = 1;
	sym_to_print = args->width > args->l ? args->width : 0;
	res = ft_strnew(sym_to_print + 1);
	start_of_res = res;
	ft_bzero(res, sym_to_print + 1);
	zero_or_space = (check_for_zero ? '0' : ' ');
	if (sym_to_print)
		while (sym_to_print > args->l++)
			*(res++) = zero_or_space;
	return (start_of_res);
}

char			*ft_handle_uint(t_param *args, va_list *ap)
{
	char					*res;
	char					*value_to_print;
	char					*prefix_postfix;
	unsigned long long int	n;

	if (args->specifier == 'U')
		n = (unsigned long long)va_arg(*ap, unsigned long long int);
	else
		n = convert_u(args, ap);
	args->l = count_digits(n);
	value_to_print = get_precision(args, n);
	prefix_postfix = get_width(args);
	if (args->flags.minus)
		res = ft_strjoin(value_to_print, prefix_postfix);
	else
		res = ft_strjoin(prefix_postfix, value_to_print);
	args->l = ft_strlen(res);
	return (res);
}

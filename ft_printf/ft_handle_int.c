/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:50:33 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/25 09:19:24 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_digits(long long n)
{
	int					i;
	unsigned long long	temp;

	if (n == 0)
		return (0);
	temp = n;
	temp = n < 0 ? -temp : temp;
	i = 1;
	while (temp > 9)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

static void		add_minus(t_param *args, char **res, long long n)
{
	if (!args->flags.plus && args->flags.space && n > 0)
		*((*res)++) = ' ';
	else if (n < 0 && (args->dot || args->flags.minus || !(args->flags.zero)))
		*((*res)++) = '-';
	else if (args->flags.plus && (args->dot ||
	args->flags.minus || !(args->flags.zero)))
		*((*res)++) = '+';
	return ;
}

static char		*get_precision(t_param *args, long long n)
{
	char	*temp;
	char	*res;
	char	*start_of_res;
	int		dig_to_print;
	int		num_of_dig;

	num_of_dig = count_digits(n);
	dig_to_print = args->precision > num_of_dig ? args->precision : num_of_dig;
	res = ft_strnew(dig_to_print + 1);
	start_of_res = res;
	add_minus(args, &res, n);
	while (args->precision > num_of_dig++)
		*(res++) = '0';
	n = n > 0 ? n : n * (-1);
	temp = ft_itoaf(n);
	if (n == 0 && args->dot)
		temp = ft_strsub("", 0, 0);
	ft_strcpy(res, temp);
	free(temp);
	args->l = ft_strlen(start_of_res);
	return (start_of_res);
}

static char		*get_width(t_param *args, long long n)
{
	char	*res;
	char	*start_of_res;
	int		sym_to_print;
	char	zero_or_space;

	zero_or_space = ' ';
	if (!args->dot && !args->flags.minus && args->flags.zero)
	{
		zero_or_space = '0';
		if (n < 0 || args->flags.space)
			(args->l)++;
	}
	sym_to_print = args->width > args->l ? args->width : 0;
	res = ft_strnew(sym_to_print + 1);
	start_of_res = res;
	if (args->flags.space && !args->flags.plus && zero_or_space == '0')
		*(res)++ = ' ';
	else if (n < 0 && zero_or_space == '0')
		*(res)++ = '-';
	else if (args->flags.plus && zero_or_space == '0' && args->l++)
		*(res)++ = '+';
	while (sym_to_print > args->l++)
		*(res)++ = zero_or_space;
	return (start_of_res);
}

char			*ft_handle_int(t_param *args, va_list *ap)
{
	char			*res;
	char			*value_to_print;
	char			*prefix_postfix;
	long long int	n;

	if (args->specifier == 'D')
		n = (long long)va_arg(*ap, long long);
	else
		n = convert(args, ap);
	args->l = count_digits(n);
	if (n < 0 || args->flags.plus || args->flags.space)
		(args->l)++;
	value_to_print = get_precision(args, n);
	prefix_postfix = get_width(args, n);
	if (args->flags.minus)
		res = ft_strjoin(value_to_print, prefix_postfix);
	else
		res = ft_strjoin(prefix_postfix, value_to_print);
	args->l = ft_strlen(res);
	return (res);
}

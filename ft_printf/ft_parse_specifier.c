/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 08:17:04 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/25 12:26:41 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		parse_flags(char *fmt, size_t *i)
{
	t_flags res;

	ft_bzero(&res, sizeof(t_flags));
	(*i)++;
	while (fmt[*i] == '+' || fmt[*i] == '-'
			|| fmt[*i] == '#' || fmt[*i] == ' ' ||
			fmt[*i] == '0')
	{
		if (fmt[*i] == '-')
			res.minus = 1;
		if (fmt[*i] == '+')
			res.plus = 1;
		if (fmt[*i] == ' ')
			res.space = 1;
		if (fmt[*i] == '0')
			res.zero = 1;
		if (fmt[*i] == '#')
			res.hashtag = 1;
		(*i)++;
	}
	return (res);
}

int			parse_width(char *fmt, size_t *i, va_list *ap, t_param *specif)
{
	int		res;
	size_t	j;

	j = *i;
	while (ft_isdigit(fmt[*i]))
		(*i)++;
	if (fmt[(*i)] == '*')
	{
		res = va_arg(*ap, int);
		if (res < 0)
		{
			res *= -1;
			specif->flags.minus = 1;
		}
		(*i)++;
	}
	else
		res = ft_atoi(fmt + j);
	return (res);
}

int			parse_precision(char *fmt, size_t *i, va_list *ap, t_param *specif)
{
	int	res;
	int	j;

	res = 0;
	if (fmt[(*i)] == '.')
	{
		specif->dot = 1;
		(*i)++;
		j = *i;
		while (ft_isdigit(fmt[*i]))
			(*i)++;
		if (fmt[(*i)] == '*')
		{
			res = va_arg(*ap, int);
			if (res < 0)
			{
				res *= -1;
				specif->flags.minus = 1;
			}
			(*i)++;
		}
		else
			res = ft_atoi(fmt + j);
	}
	return (res);
}

char		*parse_length(char *fmt, size_t *i)
{
	char	*res;

	res = ft_strnew(2);
	if (fmt[*i] == 'j' || fmt[*i] == 'z' || fmt[*i] == 't' ||
			fmt[*i] == 'L' || fmt[*i] == 'h' || fmt[*i] == 'l')
	{
		*res = fmt[(*i)++];
		if (fmt[*i] == 'l' || fmt[*i] == 'h')
		{
			*(++res) = fmt[(*i)];
			(*i)++;
			res--;
		}
	}
	return (res);
}

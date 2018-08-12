/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 21:23:52 by mpetruse          #+#    #+#             */
/*   Updated: 2018/06/20 21:37:58 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_binary(unsigned char octet)
{
	unsigned char	i;
	char			*res;
	int				counter;

	res = ft_strnew(8);
	counter = 0;
	i = 128;
	while (i)
	{
		if (i & octet)
			res[counter++] = '1';
		else
			res[counter++] = '0';
		i >>= 1;
	}
	return (res);
}

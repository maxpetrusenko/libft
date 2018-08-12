/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:20:36 by mpetruse          #+#    #+#             */
/*   Updated: 2018/06/21 18:34:13 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		slen;
	size_t		dlen;

	d = dst;
	s = src;
	slen = dstsize;
	while (slen-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	slen = dstsize - dlen;
	if (slen == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (slen != 1)
		{
			*d++ = *s;
			slen--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}

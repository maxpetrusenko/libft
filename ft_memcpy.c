/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:08:42 by mpetruse          #+#    #+#             */
/*   Updated: 2018/06/22 10:07:04 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*csrc;
	char		*cdst;

	csrc = (char *)src;
	cdst = dst;
	while (0 < n)
	{
		*cdst++ = *csrc++;
		n--;
	}
	return (dst);
}

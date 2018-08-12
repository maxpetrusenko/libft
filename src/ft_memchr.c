/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 11:51:39 by mpetruse          #+#    #+#             */
/*   Updated: 2018/06/21 20:39:20 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char *csrc;

	csrc = (unsigned char*)src;
	while (len > 0 && *csrc != (unsigned char)c)
	{
		len--;
		csrc++;
	}
	if (len == 0)
		return (NULL);
	else
		return (csrc);
}

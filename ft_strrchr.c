/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:40:01 by mpetruse          #+#    #+#             */
/*   Updated: 2018/06/21 18:33:34 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *end;

	end = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			end = (char*)s;
		s++;
	}
	if (*s == (char)c)
		return ((char*)s);
	else
		return (end);
}

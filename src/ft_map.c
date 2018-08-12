/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:42:38 by mpetruse          #+#    #+#             */
/*   Updated: 2018/05/28 18:09:40 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int lenght, int (*f)(int))
{
	int i;
	int *ptr;

	i = 0;
	ptr = (int*)malloc(sizeof(int) * lenght);
	while (i < lenght)
	{
		ptr[i] = f(tab[i]);
		i++;
	}
	return (ptr);
}

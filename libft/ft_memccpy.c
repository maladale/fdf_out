/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:17:41 by cmela             #+#    #+#             */
/*   Updated: 2019/09/19 09:18:23 by cmela            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*desti;

	if (size + 1 == 0)
		return (NULL);
	i = 0;
	source = (unsigned char *)src;
	desti = (unsigned char *)dest;
	while (i < size)
	{
		desti[i] = source[i];
		if (source[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}

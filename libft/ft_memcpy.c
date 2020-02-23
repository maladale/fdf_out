/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:16:15 by cmela             #+#    #+#             */
/*   Updated: 2019/09/19 09:16:39 by cmela            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*c1;
	char	*c2;

	if (n + 1 == 0)
		return (NULL);
	if (n == 0 || s1 == s2)
		return (s1);
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (--n)
		*c1++ = *c2++;
	*c1 = *c2;
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 08:05:35 by cmela             #+#    #+#             */
/*   Updated: 2019/09/12 08:10:40 by cmela            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *to, const char *from, size_t num)
{
	int		i;
	size_t	j;

	if (num + 1 == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (to[i] != '\0')
		i++;
	while (from[j] != '\0' && j < num)
	{
		to[i] = from[j];
		i++;
		j++;
	}
	to[i] = '\0';
	return (to);
}

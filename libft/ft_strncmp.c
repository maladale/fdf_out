/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 09:50:38 by cmela             #+#    #+#             */
/*   Updated: 2019/09/12 09:54:01 by cmela            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t i;

	if (num + 1 == 0)
		return (0);
	if (num == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2 && s1[i] == s2[i] && i < num - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

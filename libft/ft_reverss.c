/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:49:15 by cmela             #+#    #+#             */
/*   Updated: 2019/09/25 17:54:54 by cmela            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_reverss(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	result = (char*)malloc(sizeof(str));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
		i++;
	while (i > 0)
	{
		result[j] = str[i];
		j++;
		i--;
	}
	return (result);
}

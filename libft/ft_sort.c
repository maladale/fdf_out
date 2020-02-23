/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmela <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:03:29 by cmela             #+#    #+#             */
/*   Updated: 2019/09/25 17:11:31 by cmela            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort(int *sort)
{
	int i;
	int j;
	int k;
	int tmp;

	i = 0;
	j = 0;
	k = 0;
	while (sort)
		i++;
	while (j < i)
	{
		k = 0;
		while (k < i - 1)
		{
			if (sort[k] > sort[k + 1])
			{
				tmp = sort[k];
				sort[k] = sort[k + 1];
				sort[k + 1] = sort[k];
			}
			k++;
		}
		j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:04:39 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/25 20:59:40 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		x;
	int		i;
	int		*tmp;

	x = max - min;
	i = 0;
	if (x <= 0)
	{
		*range = 0;
		return (0);
	}
	tmp = (int *)malloc(sizeof(int) * x);
	if (!tmp)
	{
		*range = 0;
		return (-1);
	}
	while (min < max)
	{
		tmp[i] = min;
		i++;
		min++;
	}
	*range = tmp;
	return (x);
}
/*
int		main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	size;
	int	i = 0;

	min = 5;
	max = 10;
	size = ft_ultimate_range(&tab, min, max);
	while(i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}

}*/

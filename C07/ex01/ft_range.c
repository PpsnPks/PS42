/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:06:38 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/22 14:06:41 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ans;
	int	i;
	int	x;

	i = 0;
	x = max - min;
	if (x <= 0)
		return (0);
	ans = (int *)malloc(sizeof(int) * x);
	if (!ans)
		return (0);
	while (min < max)
	{
		ans[i] = min;
		i++;
		min++;
	}
	return (ans);
}
/*int	main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	i = 0;
	int	size;

	min = 5;
	max = 10;
	size = max - min;
	tab = ft_range(min, max);
	while(i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}

}*/

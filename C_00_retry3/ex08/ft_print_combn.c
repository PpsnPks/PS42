/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:47:25 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/09 17:42:18 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_num(int *a, int n)
{
	int	i;
	int	ch;

	i = 1;
	ch = 1;
	while (i < n)
	{
		if (a[i - 1] >= a[i])
			ch = 0;
		i++;
	}
	if (ch == 1)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(a[i] + '0');
			i++;
		}
		if (a[0] < 10 - n)
			write(1, ", ", 2);
	}
}

void	ft_print_combn(int n)
{
	int	a[10];
	int	i;

	i = 0;
	while (i < n)
		a[i++] = 0;
	while (a[0] <= (10 - n))
	{
		display_num(a, n);
		a[n - 1]++;
		i = n - 1;
		while (i > 0)
		{
			if (a[i] > 9)
			{
				a[i - 1]++;
				a[i] = 0;
			}
			i--;
		}
	}
}

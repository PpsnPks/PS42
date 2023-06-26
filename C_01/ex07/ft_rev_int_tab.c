/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:40:49 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/11 19:08:46 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	rev[100];
	int	i;

	i = 0;
	while (i < size)
	{
		rev[i] = tab[size - 1 - i];
		i++;
	}
	while (i != 0)
	{
		i--;
		tab[i] = rev[i];
	}
}
/*
int	main(void)
{
	int tab[6] = {1, 0, 0, 9, 2, 5};
	ft_rev_int_tab(tab,6);
}*/

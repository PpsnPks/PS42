/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:12:45 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/15 16:12:46 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ans;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	ans = 1;
	while (power > 0)
	{
		ans *= nb;
		power--;
	}
	return (ans);
}

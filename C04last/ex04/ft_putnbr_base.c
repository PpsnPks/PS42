/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:49:07 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/16 13:58:00 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *b)
{
	int	i;

	i = 0;
	while (b[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_checkerr(char *b)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = ft_strlen(b);
	if (b[i] == '\0' || x == 1)
		return (0);
	while (b[i] != '\0')
	{
		if (b[i] <= 32 || b[i] == 127 || b[i] == '-' || b[i] == '+')
			return (0);
		j = i + 1;
		while (b[j] != '\0')
		{
			if (b[i] == b[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	error;
	int	len;

	error = ft_checkerr(base);
	len = ft_strlen(base);
	if (error == 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			if (nbr <= len * -1)
				ft_putnbr_base((nbr / len) * -1, base);
			ft_putnbr_base((nbr % len) * -1, base);
		}
		else if (nbr < len)
			ft_putchar(base[nbr]);
		else
		{
			ft_putnbr_base(nbr / len, base);
			ft_putnbr_base(nbr % len, base);
		}
	}
}

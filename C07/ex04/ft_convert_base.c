/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:38:18 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/26 22:36:55 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_blen(long n, int len);
int		ft_find_inbase(char c, char *b);
char	*ft_putnbr_b(long n, char *b, char *string);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_checkb(char *str)
{
	int	i;
	int	j;

	i = ft_strlen(str);
	if (i <= 1)
		return (0);
	i = -1;
	while (str[++i] != '\0')
	{
		j = i;
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
		if (str[i] == '-' || str[i] == '+')
			return (0);
		while (str[++j] != '\0')
			if (str[i] == str[j])
				return (0);
	}
	return (1);
}

int	ft_sign(char *n, int *ptr_i)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (n[i] && ((n[i] >= 9 && n[i] <= 13) || n[i] == 32))
		i++;
	while (n[i] && (n[i] == '-' || n[i] == '+'))
	{
		if (n[i] == '-')
			sign *= -1;
		i++;
	}
	*ptr_i = i;
	return (sign);
}

int	ft_atoi(char *nbr, char *b)
{
	int		i;
	int		sign;
	int		len;
	int		check;
	long	ans;

	sign = ft_sign(nbr, &i);
	len = ft_strlen(b);
	ans = 0;
	while (nbr[i])
	{
		check = ft_find_inbase(nbr[i], b);
		if (check != -1)
			ans = ans * len + check;
		else
			return (ans * sign);
		i++;
	}
	return (ans * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	int		len;
	char	*string;

	if (!(ft_checkb(base_from) && ft_checkb(base_to)))
		return (NULL);
	n = ft_atoi(nbr, base_from);
	len = ft_blen(n, ft_strlen(base_to));
	string = (char *)malloc(sizeof(char) * len + 1);
	string = ft_putnbr_b(n, base_to, string);
	return (string);
}

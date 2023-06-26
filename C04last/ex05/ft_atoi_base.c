/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:28:30 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/16 16:34:41 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_checkerr(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '\0' && ft_strlen(str) == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == '-' || str[i] == '+' || str[i] == 127)
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_checksign(char *b, int *ptr_i)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while ((b[i] >= 9 && b[i] <= 13) || b[i] == 32)
		i++;
	while (b[i] == '+' || b[i] == '-')
	{
		if (b[i] == '-')
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	nb_in_base(char n, char *b)
{
	int	i;

	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	num;
	int	x;
	int	sign;

	x = ft_checkerr(base);
	i = 0;
	if (x == 1)
	{
		sign = ft_checksign(str, &i);
		num = 0;
		while (str[i] != '\0' && nb_in_base(str[i], base) != -1)
		{
			num = (num * ft_strlen(base)) + nb_in_base(str[i], base);
			i++;
		}
		return (num * sign);
	}
	else
		return (0);
}
/*int	main()
{
 	printf("5: %d\n", ft_atoi_base("ABddddd", "0123456789ABCDEF"));
}*/

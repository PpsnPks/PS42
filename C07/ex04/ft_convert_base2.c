/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:31:20 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/25 16:12:47 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_blen(long n, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n != 0)
	{
		n = n / len;
		i++;
	}
	return (i);
}

int	ft_find_inbase(char c, char *b)
{
	int	i;

	i = -1;
	while (b[++i])
	{
		if (b[i] == c)
			return (i);
	}
	return (-1);
}

char	*ft_putnbr_b(long n, char *b, char *string)
{
	int	len;
	int	i;

	len = ft_strlen(b);
	i = ft_blen(n, len);
	if (n < 0)
	{
		string[0] = '-';
		n = n * -1;
	}
	string[i] = '\0';
	if (n == 0)
		string[0] = b[0];
	while (n != 0)
	{
		string[--i] = b[n % len];
		n = n / len;
	}
	return (string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:49:02 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/26 19:31:37 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ptrlen(char **strs, int size)
{
	int	i;
	int	count;

	count = 0;
	while (--size >= 0)
	{
		i = 0;
		while (strs[size][i] != '\0')
		{
			i++;
			count++;
		}
	}
	return (count);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	put_sep(char *str, char *sep, int *ptr_k, int j)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		str[j++] = sep[i];
		i++;
	}
	*ptr_k = j;
}

int	set_i(int size, char **strs, char *sep)
{
	int	i;

	if (size > 0)
		i = ft_ptrlen(strs, size) + ((size - 1) * ft_strlen(sep)) + 1;
	else
		i = 1;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		i;
	int		j;
	int		k;

	i = set_i(size, strs, sep);
	string = (char *)malloc(sizeof(char) * i);
	if (!string)
		return (0);
	*string = 0;
	if (size == 0)
		return (string);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
			string[k++] = strs[i][j];
		if (i != size - 1)
			put_sep(string, sep, &k, k);
	}
	string[k] = '\0';
	return (string);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**strs;
	char	*separator;
	char	*result;
	int	size;

	size = 3;
	strs = (char **)malloc(3 * sizeof(char *));
	strs[0] = (char *)malloc(sizeof(char) * 5 + 1);
	strs[1] = (char *)malloc(sizeof(char) * 8 + 1);
	strs[2] = (char *)malloc(sizeof(char) * 14 + 1);
	strs[0] = "Hello";
	strs[1] = "friendpp";
	strs[2] = "you are awesome";
	separator = " ,/";
	result = ft_strjoin(size, strs, separator);
	printf("%s$\n", result);
	free(result);
}*/

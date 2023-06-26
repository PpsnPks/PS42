/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:16:13 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/25 21:02:21 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_w(char *str, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] && check_sep(str[i], sep) == 1)
			i++;
		if (str[i])
			count++;
		while (str[i] && check_sep(str[i], sep) == 0)
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**ans;
	int		w;
	int		i;
	int		j[2];

	i = 0;
	w = ft_count_w(str, charset);
	ans = (char **)malloc(sizeof(char *) * (w + 1));
	while (i <= w)
		ans[i++] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	j[0] = 0;
	i = 0;
	while (str[i] != '\0' && j[0] < w)
	{
		j[1] = 0;
		while (str[i] && check_sep(str[i], charset) == 1)
			i++;
		while (str[i] && check_sep(str[i], charset) == 0)
			ans[j[0]][j[1]++] = str[i++];
		ans[j[0]][j[1]] = '\0';
		j[0]++;
	}
	ans[j[0]] = 0;
	return (ans);
}
/*
int	main(int argc, char **argv)
{
	int		index;
	char	**split;
	(void)	argc;
	split = ft_split("Hello \0", " ,");
	index = 0;
	while (split[index])
	{
		printf("\"%s\"\n", split[index]);
		index++;
	}
	printf("\"%s\"\n", split[index]);
}*/

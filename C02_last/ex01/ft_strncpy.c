/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:13:24 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/13 09:14:53 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i++] = '\0';
	}
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
/*int	main()
{
	char	*tmp = "Hello";
	char	dst[] = "World1";
	unsigned int	k;

	k = 3;
	ft_strncpy(dst, tmp, k);
	printf("%s", dst);
	return 0;
}*/

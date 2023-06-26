/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pphingkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:38:43 by pphingkh          #+#    #+#             */
/*   Updated: 2023/06/14 19:14:04 by pphingkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i == 0)
				str[i] -= 32;
			else if (str[i - 1] <= '/')
				str[i] -= 32;
			else if (str[i - 1] >= ':' && str[i - 1] <= '@')
				str[i] -= 32;
			else if (str[i - 1] >= '[' && str[i - 1] <= '`')
				str[i] -= 32;
			else if (str[i - 1] >= '{' && str[i - 1] <= '~')
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}

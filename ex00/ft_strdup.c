/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:51:44 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/22 21:51:48 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_length(char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strdup(char *src)
{
	int		length;
	char	*result;
	int		index;

	index = 0;
	length = str_length(src);
	if ((result = (char*)malloc(length + 1 * sizeof(char))) == 0)
		return (0);
	while (index < length)
	{
		result[index] = src[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

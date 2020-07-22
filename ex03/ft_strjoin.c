/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:53:43 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/22 21:53:49 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		index++;
	}
	return (index);
}

void	ft_strjoin_input(char *result, int size, char **strs, char *sep)
{
	int index;
	int size_index;
	int result_index;

	size_index = -1;
	result_index = 0;
	while (++size_index < size)
	{
		index = -1;
		while (strs[size_index][++index] != '\0')
		{
			result[result_index] = strs[size_index][index];
			result_index++;
		}
		if (size_index != size - 1)
		{
			index = -1;
			while (sep[++index] != '\0')
			{
				result[result_index] = sep[index];
				result_index++;
			}
		}
	}
	result[result_index] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		index;
	int		total_length;
	char	*result;

	index = 0;
	total_length = 0;
	while (index < size)
	{
		total_length += ft_strlen(strs[index]);
		index++;
	}
	total_length += size * ft_strlen(sep);
	if ((result = (char*)malloc((total_length) * sizeof(char))) == 0)
		return (0);
	ft_strjoin_input(result, size, strs, sep);
	return (result);
}

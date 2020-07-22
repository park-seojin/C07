/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:55:30 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/22 21:55:34 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (src[index] && index < n)
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int		ft_is_separator(char c, char *charset)
{
	int		index;

	index = 0;
	while (charset[index])
	{
		if (c == charset[index])
			return (1);
		index++;
	}
	return (0);
}

char	*get_next_word(char **ptr, char *charset, int *length)
{
	int		index;
	char	*str_start;

	*length = 0;
	str_start = 0;
	index = 0;
	while ((*ptr)[index])
	{
		if (ft_is_separator((*ptr)[index], charset) && str_start != 0)
		{
			*ptr = str_start + (*length);
			return (str_start);
		}
		else if (!ft_is_separator((*ptr)[index], charset) && str_start == 0)
			str_start = &(*ptr)[index];
		if (!ft_is_separator((*ptr)[index], charset))
			*length = *length + 1;
		index++;
	}
	*ptr = str_start + (*length);
	if ((*length) == 0)
		return (0);
	return (str_start);
}

char	**make_result(char *str, char *charset)
{
	int		count;
	int		length;
	char	*ptr;
	char	**result;

	count = 0;
	length = 0;
	ptr = str;
	while (get_next_word(&ptr, charset, &length))
		count++;
	if ((result = (char **)malloc(sizeof(char *) * (count + 1))) == 0)
		return (0);
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		index;
	int		length;
	char	*next_str;
	char	*ptr;
	char	**result;

	if (!(result = make_result(str, charset)))
		return (0);
	index = 0;
	ptr = str;
	while ((next_str = get_next_word(&ptr, charset, &length)))
	{
		if ((result[index] = (char *)malloc(sizeof(char) * length + 1)) == 0)
			return (0);
		ft_strncpy(result[index], next_str, length);
		index++;
	}
	result[index] = 0;
	return (result);
}

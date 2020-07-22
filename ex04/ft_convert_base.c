/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:54:25 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/22 21:54:28 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		is_space(char c);
int		ft_number_length(unsigned int number, int base_count, int is_negative);

int		check_base(char *base)
{
	int i;
	int index;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\n' ||
				base[i] == '\t' || base[i] == '\v' ||
				base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
			return (0);
		index = i + 1;
		while (base[index] != '\0')
		{
			if (base[i] == base[index])
				return (0);
			index++;
		}
		i++;
	}
	return (1);
}

int		inspection_char(char *base, char nbr)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == nbr)
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_buffer_base(char *base, unsigned int number, int is_negative)
{
	int		index;
	int		base_count;
	int		length;
	char	*result;

	base_count = ft_strlen(base);
	length = ft_number_length(number, base_count, is_negative);
	if (!(result = (char *)malloc((length + 1) * sizeof(char))))
		return (0);
	if (is_negative)
		result[0] = '-';
	index = is_negative ? 1 : 0;
	while (index < length)
	{
		result[length - (!is_negative) - index++] = base[number % base_count];
		number = number / base_count;
	}
	result[length] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				from_len;
	int				is_negative;
	int				temp;
	unsigned int	result;

	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	from_len = ft_strlen(base_from);
	while (is_space(*nbr))
		nbr++;
	is_negative = 1;
	while (*nbr == '+' || *nbr == '-')
		if (*(nbr++) == '-')
			is_negative = is_negative * -1;
	result = 0;
	while ((temp = inspection_char(base_from, *nbr)) != -1)
	{
		result = result * from_len + temp;
		nbr++;
	}
	is_negative = (result == 0 ? 1 : is_negative);
	return (ft_buffer_base(base_to, result, (is_negative > 0 ? 0 : 1)));
}

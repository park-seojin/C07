/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:54:50 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/22 21:54:53 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

int		is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_number_length(unsigned int number, int base_count, int negative)
{
	unsigned int length;

	length = negative ? 1 : 0;
	while (1)
	{
		length++;
		if (number / base_count == 0)
		{
			break ;
		}
		number /= base_count;
	}
	return (length);
}

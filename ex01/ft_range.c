/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:52:41 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/22 21:52:44 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int range;
	int	*result;
	int index;

	if (min >= max)
	{
		return (0);
	}
	range = max - min;
	if ((result = (int*)malloc((range - 1) * sizeof(int))) == 0)
		return (0);
	index = 0;
	while (index < range)
	{
		result[index] = min + index;
		index++;
	}
	return (result);
}

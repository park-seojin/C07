/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojpark <qkrtjwls8546@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:53:13 by seojpark          #+#    #+#             */
/*   Updated: 2020/07/22 21:53:15 by seojpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int range_index;
	int	*result;
	int index;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	range_index = max - min;
	if ((result = (int*)malloc((range_index - 1) * sizeof(int))) == 0)
	{
		*range = 0;
		return (-1);
	}
	index = 0;
	while (index < range_index)
	{
		result[index] = min + index;
		index++;
	}
	*range = result;
	return (range_index);
}

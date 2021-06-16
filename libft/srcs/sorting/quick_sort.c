/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:36:45 by isel-jao          #+#    #+#             */
/*   Updated: 2021/05/14 08:39:42 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[low];
	i = high;
	j = high;
	while (j >= low)
	{
		if (arr[j] > pivot)
		{
			swap(arr[j], arr[i]);
			i--;
		}
		j--;
	}
	swap(arr[i], arr[low]);
	return (i);
}

void	quickSort(int *arr, int low, int high)
{
	int	p;

	if (low >= high)
		return ;
	p = partition(arr, low, high);
	quickSort(arr, low, p - 1);
	quickSort(arr, p + 1, high);
}

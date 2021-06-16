/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao <isel-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:30:16 by isel-jao          #+#    #+#             */
/*   Updated: 2021/05/14 08:34:17 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	insert(int *arr, int i)
{
	int	t;

	while (i > 0 && arr[i] < arr[i - 1])
	{
		t = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = t;
		i--;
	}
}

void	insertionSort(int arr[], int n)
{
	int	i;

	i = 1;
	while (i < n)
	{
		insert(arr, i);
		i++;
	}
}

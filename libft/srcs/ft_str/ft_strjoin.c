/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yqodsi <yqodsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:59:45 by yqodsi            #+#    #+#             */
/*   Updated: 2021/06/24 15:59:47 by yqodsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;

	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	i = (ft_strlen(s1) + ft_strlen(s2) + 1);
	ret = malloc(i);
	while (*s1)
	{
		*ret = *s1;
		ret++;
		s1++;
	}
	while (*s2)
	{
		*ret = *s2;
		ret++;
		s2++;
	}
	*ret = '\0';
	return (ret - i + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:48:03 by najeuneh          #+#    #+#             */
/*   Updated: 2024/04/15 11:33:01 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*find;

	str = (char *)haystack;
	find = (char *)needle;
	i = 0;
	if (needle[i] == '\0')
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == find[j])
		{
			while (str[i + j] == find[j] && find[j] && (i + j) < len)
			{
				j++;
			}
			if (find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

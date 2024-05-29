/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:21:22 by najeuneh          #+#    #+#             */
/*   Updated: 2024/04/15 17:15:19 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*st1;
	char	*st2;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	st2 = (char *)s2;
	st1 = (char *)s1;
	str = malloc((ft_strlen(st1) + ft_strlen(st2)) + 1);
	if (str == NULL)
		return (NULL);
	while (st1[++i])
		str[i] = st1[i];
	while (st2[++j])
		str[i + j] = s2[j];
	return (str[i + j] = '\0', str);
}

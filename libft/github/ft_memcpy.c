/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:48:17 by najeuneh          #+#    #+#             */
/*   Updated: 2024/04/15 11:00:49 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*sdest;
	char	*ssrc;
	size_t	i;

	i = 0;
	ssrc = (char *)src;
	sdest = dst;
	if (!dst && !src)
		return (NULL);
	while (n)
	{
		sdest[i] = ssrc[i];
		i++;
		n--;
	}
	return (sdest);
}

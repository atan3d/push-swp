/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najeuneh <najeuneh@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:06:04 by najeuneh          #+#    #+#             */
/*   Updated: 2024/04/15 16:46:05 by najeuneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*sdest;
	const char	*ssrc;

	ssrc = src;
	sdest = dst;
	if (dst < src)
	{
		while (len)
		{
			*sdest = *ssrc;
			sdest++;
			ssrc++;
			len--;
		}
	}
	else if (src < dst)
	{
		while (len)
		{
			sdest[len - 1] = ssrc[len - 1];
			len--;
		}
	}
	return (dst);
}

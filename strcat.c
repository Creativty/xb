/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:07:52 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/13 13:21:40 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"

char	*xb_strcat(char	*dst, const char *src)
{
	return (xb_strncat(dst, src, xb_strlen(src)));
}

char	*xb_strncat(char *dst, const char *src, int count)
{
	int	i;
	int	offset;

	i = 0;
	offset = xb_strlen(dst);
	while (i < count)
	{
		dst[offset + i] = src[i];
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:01:36 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/13 13:57:21 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"

char	*xb_strcpy(char *dst, const char *src)
{
	return (xb_strncpy(dst, src, xb_strlen(src)));
}

char	*xb_strncpy(char *dst, const char *src, int src_len)
{
	int	i;

	i = 0;
	if (dst == NULL || src == NULL || src_len == 0)
		return (dst);
	while (i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

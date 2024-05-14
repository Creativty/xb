/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strslice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:32:41 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/13 13:56:17 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"
#include <stdlib.h>

char	*xb_strslice(const char *src, int offset, int length)
{
	char	*dst;
	int		src_len;

	if (!src || offset < 0 || length < 0)
		return (NULL);
	src_len = xb_strlen(src);
	if (offset + length > src_len)
		length = src_len - offset;
	dst = malloc(sizeof(char) * (length + 1));
	if (dst)
	{
		xb_strncpy(dst, &src[offset], length);
		dst[length] = '\0';
	}
	return (dst);
}

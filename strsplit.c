/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:11:37 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/14 09:43:22 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"
#include <stdlib.h>

static int	xb_strsplit_count(const char *src, char c)
{
	int	i;
	int	count;
	int	should_increment;

	i = 0;
	count = 0;
	should_increment = 0;
	if (src[i] != c)
		count++;
	while (src[i])
	{
		if (src[i] == c)
			should_increment = 1;
		else if (should_increment)
		{
			should_increment = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static void	xb_strsplit_populate(const char *src, char c, char **out, int count)
{
	int	length;
	int	offset;
	int	split_index;

	length = 0;
	offset = 0;
	split_index = 0;
	while (split_index < count)
	{
		while (src[offset] == c)
			offset++;
		length = xb_strpos(&src[offset], c);
		if (length == -1)
			length = xb_strlen(src) - offset;
		out[split_index] = xb_strslice(src, offset, length);
		offset += length;
		split_index++;
	}
	out[split_index] = NULL;
}

char	**xb_strsplit(const char *src, char c)
{
	int		splits_count;
	char	**splits;

	if (!src)
		return (NULL);
	splits_count = xb_strsplit_count(src, c);
	splits = malloc(sizeof(char *) * (splits_count + 1));
	if (splits)
		xb_strsplit_populate(src, c, splits, splits_count);
	return (splits);
}

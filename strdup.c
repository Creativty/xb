/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:58:42 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/14 10:53:51 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"

char	*xb_strdup(const char *src)
{
	return (xb_strndup(src, xb_strlen(src)));
}

char *xb_strndup(const char *src, int count)
{
	return (xb_strslice(src, 0, count));
}

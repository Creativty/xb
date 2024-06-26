/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:58:49 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/14 11:08:13 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"
#include <limits.h>

int	xb_strlen(const char *str)
{
	int	len;

	len = 0;
	if (str != NULL)
		while (str[len] && len < INT_MAX)
			len++;
	return (len);
}

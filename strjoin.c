/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:58:39 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/13 13:06:30 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"
#include <stdlib.h>

char	*xb_strjoin(const char *lhs, const char *rhs)
{
	int		lhs_len;
	int		rhs_len;
	char	*res;

	lhs_len = xb_strlen(lhs);
	rhs_len = xb_strlen(rhs);
	res = malloc(sizeof(char) * (lhs_len + rhs_len + 1));
	if (res)
	{
		xb_strncpy(res, lhs, lhs_len);
		xb_strncpy(&res[lhs_len], rhs, rhs_len);
		res[lhs_len + rhs_len] = '\0';
	}
	return (res);
}

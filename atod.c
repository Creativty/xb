/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:22:39 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/14 13:33:14 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb_internal.h"

double	xb_internal_atod_mantissa(int i_mantissa)
{
	double	mantissa;

	mantissa = (double)i_mantissa;
	while (mantissa >= 1.00)
		mantissa /= 10.0;
	return (mantissa);
}

double	xb_atod(const char *src)
{
	int	i;
	int	lhs;
	int	rhs;
	int	dot_pos;

	lhs = xb_atoi(src);
	dot_pos = xb_strpos(src, '.');
	if (dot_pos == -1)
		return ((double)lhs);
	i = 0;
	rhs = xb_internal_atoi(&src[dot_pos + 1], 0);
	return ((double)lhs + xb_internal_atod_mantissa(rhs));
}

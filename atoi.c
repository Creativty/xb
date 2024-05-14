/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:07:43 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/14 13:22:19 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"
#include "xb_internal.h"

int	xb_atoi(const char *src)
{
	return (xb_internal_atoi(src, 1));
}

int	xb_internal_atoi(const char *src, int accept_signs)
{
	int		idx;
	long	nbr;
	int		sgn;

	idx = 0;
	nbr = 0;
	sgn = 1;
	if (src)
	{
		while (accept_signs && src[idx] == '-')
		{
			sgn *= -1;
			idx += +1;
		}
		while (xb_strhas("0123456789", src[idx]))
			nbr = (nbr * 10) + (long)(src[idx++] - '0');
	}
	return ((int)(sgn * nbr));
}

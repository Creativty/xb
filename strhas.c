/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:24:29 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/13 15:16:14 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"

int	xb_strhas(const char *hay, char needle)
{
	return (xb_strnhas(hay, needle, xb_strlen(hay)));
}

int	xb_strnhas(const char *hay, char needle, int count)
{
	return (xb_strnpos(hay, needle, count) != -1);
}

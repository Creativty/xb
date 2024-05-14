/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strpos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:15:25 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/13 17:44:02 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"

int	xb_strpos(const char *hay, char needle)
{
	return (xb_strnpos(hay, needle, xb_strlen(hay)));
}

int	xb_strnpos(const char *hay, char needle, int count)
{
	int	i;

	if (hay != NULL && needle != '\0')
	{
		i = 0;
		while (hay[i] && i < count)
		{
			if (hay[i] == needle)
				return (i);
			i++;
		}
	}
	return (-1);
}

int	xb_strnpos_not(const char *hay, int not_needle, int count)
{
	int	i;

	if (hay != NULL && not_needle != '\0')
	{
		i = 0;
		while (hay[i] && i < count)
		{
			if (hay[i] != not_needle)
				return (i);
			i++;
		}
	}
	return (-1);
}

int	xb_strnpos_lamda(const char *hay, int (*lambda)(char), int count)
{
	int	i;

	if (hay != NULL && lambda != NULL)
	{
		i = 0;
		while (hay[i] && i < count)
		{
			if (lambda(hay[i]))
				return (i);
			i++;
		}
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_uptime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:45:37 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/14 13:35:06 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"
#include <stdlib.h>

double	xb_unix_uptime(void)
{
	char	*filedata;
	double	uptime;

	filedata = xb_unix_read_file("/proc/uptime");
	if (!filedata)
		return (-1.0);
	uptime = xb_atod(filedata);
	return (free(filedata), uptime);
}

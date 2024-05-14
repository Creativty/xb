/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:47:36 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/14 09:55:34 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

void	xb_free(int count, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, count);
	while (count-- > 0)
		free(va_arg(args, void *));
	va_end(args);
}

void	xb_free_list(int count, void **list)
{
	int	i;

	i = 0;
	while (i < count)
		free(list[i++]);
	free(list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xb_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:37:46 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/14 09:54:50 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"
#include <stdio.h>

int	main(void) {
	char **splits = NULL;

	splits = xb_strsplit("   hello   world  ", ' ');
	for (int i = 0; splits && splits[i]; i++)
		printf("'%s'\n", splits[i]);
	xb_free_list(xb_arrlen((void **)splits), (void **)splits);

	return (0);
}

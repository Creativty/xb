/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:13:37 by abderrahim        #+#    #+#             */
/*   Updated: 2024/05/12 17:28:18 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"
#include <stdio.h>

void	stack_print(t_stack *stack, char *label)
{
	int				i;
	t_stack_node	*iter;

	i = 0;
	if (!label)
		label = "stack";
	while (i < stack->length)
	{
		iter = stack_get(stack, i++);
		if (iter)
			printf("%d\n", iter->value);
	}
	printf("%s has %d items\n", label, stack->length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:29:07 by abderrahim        #+#    #+#             */
/*   Updated: 2024/05/12 17:36:09 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "xb.h"

t_stack_node	*stack_get_last(t_stack *stack)
{
	t_stack_node	*node;

	node = stack->head;
	while (node && node->next)
		node = node->next;
	return (node);
}

t_stack_node	**stack_getref(t_stack *stack, int index)
{
	t_stack_node	**ref;

	ref = &stack->head;
	if (index < 0)
		return (NULL);
	if (index == 0)
		return (&stack->head);
	while (*ref && index > 0)
	{
		ref = &(*ref)->next;
		index--;
	}
	return (ref);
}

t_stack_node	*stack_get(t_stack *stack, int index)
{
	t_stack_node	*node;

	node = *stack_getref(stack, index);
	return (node);
}

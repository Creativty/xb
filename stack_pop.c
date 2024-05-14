/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:29:35 by abderrahim        #+#    #+#             */
/*   Updated: 2024/05/12 15:53:19 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "xb.h"

t_stack_node	*stack_pop_head(t_stack *stack)
{
	t_stack_node	*node;

	node = stack->head;
	if (node)
	{
		stack->head = node->next;
		node->next = NULL;
		stack->length--;
	}
	return (node);
}

t_stack_node	*stack_pop_tail(t_stack *stack)
{
	t_stack_node	*iter;
	t_stack_node	*tail;

	tail = NULL;
	if (stack != NULL && stack->head != NULL)
	{
		iter = stack->head;
		tail = stack->head;
		if (!stack->head->next)
		{
			stack->head = NULL;
			stack->length--;
			return (tail);
		}
		while (iter)
		{
			if (iter->next && !iter->next->next)
			{
				tail = iter->next;
				iter->next = NULL;
				break ;
			}
			iter = iter->next;
		}
		stack->length--;
	}
	return (tail);
}

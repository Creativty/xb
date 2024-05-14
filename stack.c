/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:24:50 by abderrahim        #+#    #+#             */
/*   Updated: 2024/05/12 15:53:19 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "xb.h"

t_stack	*stack_new_from_array(int *list, int len)
{
	int				i;
	t_stack			*stack;
	t_stack_node	*node;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		i = 0;
		stack->head = NULL;
		stack->length = 0;
		if (!list || len <= 0)
			return (stack);
		node = stack_node_new(list[i++]);
		stack->head = node;
		while (i < len)
		{
			if (!node)
				return (stack_free(stack), NULL);
			node->next = stack_node_new(list[i++]);
			node = node->next;
		}
		stack->length = i;
	}
	return (stack);
}

t_stack	*stack_new_empty(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		stack->head = NULL;
		stack->length = 0;
	}
	return (stack);
}

void	stack_free(t_stack *stack)
{
	t_stack_node	*next;
	t_stack_node	*current;

	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

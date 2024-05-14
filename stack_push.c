/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:33:30 by abderrahim        #+#    #+#             */
/*   Updated: 2024/05/12 15:53:05 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"

void	stack_push_head(t_stack *stack, t_stack_node *node)
{
	int	length;

	if (!node)
		return ;
	length = stack_node_length(node);
	if (stack->head)
		node->next = stack->head;
	stack->head = node;
	stack->length += length;
}

void	stack_push_tail(t_stack *stack, t_stack_node *node)
{
	t_stack_node	*iter;
	if (!node)
		return ;
	iter = stack->head;
	while (iter && iter->next)
		iter = iter->next;
	if (iter)
		iter->next = node;
	else
		stack->head = node;
	stack->length++;
}

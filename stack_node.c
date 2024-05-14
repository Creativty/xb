/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:26:04 by abderrahim        #+#    #+#             */
/*   Updated: 2024/05/12 15:53:19 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "xb.h"

t_stack_node	*stack_node_new(int value)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (node)
	{
		node->next = NULL;
		node->value = value;
	}
	return (node);
}

int	stack_node_length(t_stack_node	*node)
{
	int	i;

	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	stack_node_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*c;

	if (!a || !b)
		return ;
	// Swap values themselves
	c = *b;
	*b = *a;
	*a = c;
	// Swap nexts
	c = (*b)->next;
	(*b)->next = (*a)->next;
	(*a)->next = c;
}

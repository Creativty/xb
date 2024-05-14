/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lambda.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:34:37 by abderrahim        #+#    #+#             */
/*   Updated: 2024/05/12 15:53:19 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "xb.h"

void	stack_foreach(t_stack *stack, void (*lambda)(int, t_stack_node*))
{
	int				i;
	t_stack_node	*node;

	if (!stack)
		return ;
	i = 0;
	node = stack->head;
	while (node)
	{
		lambda(i, node);
		node = node->next;
		i++;
	}
}

t_stack	*stack_map(t_stack *src, t_stack_node *(*lambda)(int, t_stack_node*))
{
	int				i;
	t_stack			*dst;
	t_stack_node	*src_iter;
	t_stack_node	*dst_iter;

	if (!src)
		return (NULL);
	dst = stack_new_empty();
	if (dst)
	{
		if (src->head == NULL || src->length == 0)
			return (dst);
		i = 0;
		src_iter = src->head;
		while (src_iter)
		{
			dst_iter = lambda(i, src_iter);
			if (!dst_iter)
				return (stack_free(dst), NULL);
			stack_push_tail(dst, dst_iter);
			src_iter = src_iter->next;
			i++;
		}
	}
	return (dst);
}

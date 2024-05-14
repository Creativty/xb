/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abderrahim <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:34:01 by abderrahim        #+#    #+#             */
/*   Updated: 2024/05/12 15:53:00 by abderrahim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "xb.h"

void	stack_reverse(t_stack *stack)
{
	t_stack_node	*iter;
	t_stack_node	*head;

	if (!stack)
		return ;
	head = stack_pop_tail(stack);
	iter = head;
	while (1)
	{
		iter->next = stack_pop_tail(stack);
		iter = iter->next;
		if (iter == NULL)
			break ;
	}
	stack_push_head(stack, head);
}

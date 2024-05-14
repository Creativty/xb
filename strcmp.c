/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:55:01 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/13 13:38:42 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	xb_strcmp(const char *lhs, const char *rhs)
{
	int	i;

	i = 0;
	while (lhs[i] && lhs[i] == rhs[i])
		i++;
	return (lhs[i] - rhs[i]);
}

int	xb_strncmp(const char *lhs, const char *rhs, int count)
{
	int	i;

	i = 0;
	while (i < count && (lhs[i] == rhs[i]))
		i++;
	return (lhs[i] - rhs[i]);
}

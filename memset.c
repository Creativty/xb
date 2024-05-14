/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:21:13 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/13 15:17:20 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*xb_memset(void *area, char byte, int count)
{
	int		i;
	char	*dest;

	if (area)
	{
		i = 0;
		dest = (char *)area;
		while (i < count)
			dest[i++] = byte;
	}
	return (area);
}

void	*xb_bzero(void *area, int count)
{
	return (xb_memset(area, '\0', count));
}

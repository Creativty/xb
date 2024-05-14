/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_read_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:46:17 by aindjare          #+#    #+#             */
/*   Updated: 2024/05/14 11:08:01 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xb.h"
#include "xb_internal.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

char	*xb_unix_read_fd(int fd)
{
	ssize_t		count;
	char		*data;
	char		*inter;
	char		buffer[UNIX_READ_BUFFER_SIZE + 1];

	data = NULL;
	inter = NULL;
	if (fd < 0)
		return (data);
	while (1)
	{
		xb_memset(buffer, '\0', UNIX_READ_BUFFER_SIZE);
		count = read(fd, buffer, UNIX_READ_BUFFER_SIZE);
		if (count == -1)
			return (free(data), NULL);
		if (count == 0)
			return (data);
		inter = xb_strjoin(data, buffer);
		free(data);
		data = inter;
	}
}

char	*xb_unix_read_file(const char *file_path)
{
	int		fd;
	char	*data;

	if (file_path == NULL)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	data = xb_unix_read_fd(fd);
	return (close(fd), data);
}

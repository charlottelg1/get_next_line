/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:11:29 by cle-gran          #+#    #+#             */
/*   Updated: 2021/06/13 17:18:48 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_error(int fd, char **line, char **buf)
{
	if (!line || fd < 0 || read(fd, NULL, 0) != 0)
		return (-1);
	if (!*buf)
		*buf = ft_strdup("");
	return (0);
}

int	end_file(char **line, char **buf)
{
	*line = ft_strdup(*buf);
	free(*buf);
	*buf = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	char		*reste;
	char		read_buf[BUFFER_SIZE + 1];
	char		*ptrn;
	int			lu;

	if (check_error(fd, line, &buf) == -1)
		return (-1);
	while (!(ft_strchr(buf, '\n')))
	{
		lu = read(fd, read_buf, BUFFER_SIZE);
		if (lu < 0)
			return (-1);
		read_buf[lu] = '\0';
		if (lu == 0)
			return (end_file(line, &buf));
		buf = ft_strjoin(buf, read_buf);
	}
	ptrn = ft_strchr(buf, '\n');
	*ptrn++ = '\0';
	*line = ft_strdup(buf);
	reste = ft_strdup(ptrn);
	free(buf);
	buf = reste;
	return (1);
}

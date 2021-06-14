/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 22:02:44 by root              #+#    #+#             */
/*   Updated: 2021/06/12 17:42:54 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	unsigned int	len;
	char			*res;
	unsigned int	i;

	i = 0;
	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (str[i] != 0)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(char *str, char n)
{
	while (*str != n)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	total_len;
	unsigned int	i;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

int	check_error(int fd, char **line)
{
	if (!line || fd < 0 || read(fd, NULL, 0) > 0)
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf;
	char		*reste;
	char		read_buf[BUFFER_SIZE + 1];
	char		*ptrn;
	int			lu;

	if (check_error(fd, line) == -1)
		return (-1);
	if (!buf)
		buf = ft_strdup("");
	while (!(ft_strchr(buf, '\n')))
	{
		lu = read(fd, read_buf, BUFFER_SIZE);
		if (lu < 0)
			return (-1);
		read_buf[lu] = '\0';
		if (lu == 0)
		{
			*line = ft_strdup(buf);
			free(buf);
			buf = NULL;
			return (0);
		}
		buf = ft_strjoin(buf, read_buf);
	}
	ptrn = ft_strchr(buf, '\n');
	*ptrn = '\0';
	ptrn++;
	*line = ft_strdup(buf);
	reste = ft_strdup(ptrn);
	free(buf);
	buf = reste;
	return (1);
}

int	main(void)
{
	int fd;
	char *line;
	int ret;

	line = NULL;
	fd = open("fichier.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("%d |%s\n", ret, line);
	free(line);
}

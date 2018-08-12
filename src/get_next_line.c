/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 22:23:56 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/13 10:09:58 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	find_nl(int fd, char **buf, char **line)
{
	char		*new_line;
	char		*tmp;

	while ((new_line = ft_strchr(buf[fd], '\n')))
	{
		tmp = buf[fd];
		*new_line = '\0';
		*line = ft_strsub(buf[fd], 0, new_line - buf[fd]);
		buf[fd] = ft_strdup(new_line + 1);
		free(tmp);
		return (1);
	}
	while (*buf[fd])
	{
		*line = ft_strnew(ft_strlen(buf[fd]));
		ft_strcpy(*line, buf[fd]);
		buf[fd] = ft_memalloc(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}

static	int	ft_read(int fd, char **line)
{
	char		*buf;
	char		*tmp;
	int			i;

	buf = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!line[fd])
		{
			line[fd] = ft_strnew(ft_strlen(buf));
			ft_strcpy(line[fd], buf);
		}
		else
		{
			tmp = line[fd];
			line[fd] = ft_strjoin(line[fd], buf);
			free(tmp);
		}
		ft_memset(buf, 0, BUFF_SIZE);
	}
	free(buf);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static	char	*buf[FDS];

	if (!line || fd < 0 || BUFF_SIZE < 0 || (ft_read(fd, &buf[fd]) < 0) ||
fd > FDS)
		return (-1);
	if (find_nl(fd, &buf[fd], line) == 1)
		return (1);
	return (0);
}

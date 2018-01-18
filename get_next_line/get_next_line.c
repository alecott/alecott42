/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 09:06:26 by alecott           #+#    #+#             */
/*   Updated: 2017/12/18 18:43:59 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_buffer(int const fd, char **buffer)
{
	char	*buff;
	char	*tmp;
	int		ret;

	buff = malloc(sizeof(char*) * (BUFF_SIZE + 1));
	if (buff == NULL)
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	tmp = buffer[fd];
	buffer[fd] = ft_strjoin(tmp, buff);
	ft_memdel((void**)&buff);
	ft_memdel((void**)&tmp);
	return (ret);
}

static char		*algo_get_next_line(t_m *m, int const fd)
{
	char	*dest;
	int		len;
	int		j;
	int		y;

	len = 0;
	j = 0;
	y = m->i[fd];
	while (m->buffer[fd][m->i[fd]] != '\0' && m->buffer[fd][m->i[fd]] != '\n')
	{
		m->i[fd]++;
		len++;
	}
	dest = malloc(sizeof(char*) * len);
	if (dest == NULL)
		return (NULL);
	while (j < len)
	{
		dest[j] = m->buffer[fd][y];
		j++;
		y++;
	}
	dest[j] = '\0';
	m->i[fd]++;
	return (dest);
}

int				check_get_next_line(t_m *m, int const fd, char **line, int ret)
{
	*line = NULL;
	if (m->buffer[fd][0] != 0 &&
			(size_t)m->i[fd] >= ft_strlen(m->buffer[fd]))
	{
		ft_strdel(&m->buffer[fd]);
		return (0);
	}
	while (ret > 0)
		ret = read_buffer(fd, m->buffer);
	if (ret < 0)
		return (-1);
	if (m->buffer[fd][m->i[fd]] == '\0')
	{
		ft_strdel(&m->buffer[fd]);
		return (0);
	}
	if (m->buffer[fd][m->i[fd]] == '\n')
	{
		m->i[fd]++;
		*line = ft_strdup("");
		return (1);
	}
	*line = algo_get_next_line(m, fd);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_m	*m;
	int			ret;

	ret = 1;
	if (fd < 0 || line == NULL || read(fd, 0, 0) < 0)
		return (-1);
	if (m == NULL)
		m = ft_memalloc(sizeof(t_m));
	if (m == NULL)
		return (-1);
	if (!m->buffer)
		m->buffer = ft_memalloc(sizeof(char*) * 4200);
	if (!m->i)
		m->i = ft_memalloc(sizeof(int) * 4200);
	if (line == NULL)
		return (-1);
	if (!m->buffer[fd] && !(m->buffer[fd] = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	ret = check_get_next_line(m, fd, line, ret);
	return (ret);
}

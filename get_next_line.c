/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:45:25 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/02/04 23:26:42 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_before(int fd, char *save)
{
	ssize_t	read_bytes;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr(save, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_return(char *save)
{
	char		*line;
	size_t		idx;

	idx = 0;
	if (!save[idx])
		return (0);
	while (save[idx] != '\n' && save[idx] != '\0')
		idx++;
	line = malloc(idx + 1);
	if (!line)
		return (0);
	idx = 0;
	while (save[idx] != '\n' && save[idx] != '\0')
	{
		line[idx] = save[idx];
		idx++;
	}
	if (save[idx] == '\n')
	{
		line[idx] = save[idx];
		idx++;
	}
	line[idx] = '\0';
	return (line);
}

char	*give_save(char *save)
{
	size_t	i_save;
	size_t	i_line;
	char	*line;

	i_save = 0;
	i_line = 0;
	while (save[i_save] != '\0' && save[i_save] != '\n')
		i_save++;
	if (save[i_save] == '\0')
	{
		free(save);
		return (0);
	}
	line = malloc(ft_strlen(save) - i_save + 1);
	if (!line)
		return (0);
	i_save++;
	while (save[i_save] != '\0')
		line[i_line++] = save[i_save++];
	free(save);
	line[i_line] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = get_before(fd, save);
	if (!save)
	{
		free(save);
		return (0);
	}
	ret = get_return(save);
	save = give_save(save);
	return (ret);
}

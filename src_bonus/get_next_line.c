/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:29:59 by manykhac          #+#    #+#             */
/*   Updated: 2022/11/06 13:30:08 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char	*fill_line(char *line, int fd, int len)
{
	char	buff[BUFFER_SIZE + 1];

	while (1)
	{
		len = read(fd, buff, BUFFER_SIZE);
		buff[len] = 0;
		if (len == -1)
			return (0);
		if (!line)
			line = ft_strdup(buff);
		else
			line = ft_strjoin1(line, buff);
		if (ft_strchr(buff, '\n') || len == 0)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	int			len;
	int			line_len;
	char		*temp;
	char		*ret_line;

	len = 1;
	line = fill_line(line, fd, len);
	if (!line)
		return (0);
	line_len = ft_strlen1(line) - ft_strlen1(ft_strchr(line, '\n')) + 1;
	ret_line = ft_substr(line, 0, line_len);
	temp = line;
	line = ft_substr(line, line_len, ft_strlen1(line) - line_len);
	free(temp);
	return (ret_line);
}

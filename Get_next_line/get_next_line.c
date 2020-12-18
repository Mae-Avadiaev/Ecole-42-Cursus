/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:27:02 by mclown            #+#    #+#             */
/*   Updated: 2020/12/04 16:19:58 by mclown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_buffer_and_return_value(char **buffer, int value)
{
	free(*buffer);
	return (value);
}

int	fill_tails(char **tails, int fd)
{
	int		end;
	char	*buffer;
	char	*ptr;

	if (!(buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((end = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[end] = '\0';
		if (!(*tails))
			*tails = ft_strdup(buffer);
		else
		{
			ptr = *tails;
			*tails = ft_strjoin(*tails, buffer);
			free(ptr);
		}
		if (*tails == NULL)
			free_buffer_and_return_value(&buffer, -1);
		if (ft_strchr(*tails, '\n'))
			break ;
	}
	free(buffer);
	return (end == -1 ? -1 : 0);
}

int	fill_the_line(char *ptr_n, char **tails, char **line)
{
	char	*ptr;

	*ptr_n = '\0';
	*line = ft_strdup(*tails);
	ptr_n++;
	ptr = *tails;
	*tails = ft_strdup(ptr_n);
	free(ptr);
	if (!*tails)
		return (-1);
	if (!*line)
	{
		free(*tails);
		tails = NULL;
		return (-1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*tails[5000];
	char		*ptr_n;

	if (fd == -1 || BUFFER_SIZE < 1 || line == NULL ||
	fill_tails(&tails[fd], fd))
		return (-1);
	if (!tails[fd])
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	if ((ptr_n = ft_strchr(tails[fd], '\n')))
	{
		if (fill_the_line(ptr_n, &tails[fd], line))
			return (-1);
		return (1);
	}
	else
	{
		*line = ft_strdup(tails[fd]);
		free(tails[fd]);
		tails[fd] = NULL;
		return ((!*line ? -1 : 0));
	}
}

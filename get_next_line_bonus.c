/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:58:22 by alvutina          #+#    #+#             */
/*   Updated: 2024/05/13 10:58:26 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start > strlen - 1)
		len = 0;
	else if (start + len > strlen - 1)
		len = strlen - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

static void	ft_free(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}

static char	*ft_for_norm(int fd, char **buf, char **current_line)
{
	ft_free(buf);
	ft_free(&current_line[fd]);
	return (NULL);
}

static char	*ft_extract_line_segment(char **str)
{
	int		i;
	char	*segment;
	char	*temp;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	segment = ft_substr(*str, 0, i + 1);
	temp = ft_strdup(*str);
	ft_free(str);
	*str = ft_substr(temp, i + 1, ft_strlen(temp));
	ft_free(&temp);
	if (!ft_strchr(segment, '\n'))
	{
		if (!ft_strlen(segment))
			ft_free(&segment);
		ft_free(str);
	}
	return (segment);
}

char	*get_next_line(int fd)
{
	int			size;
	char		*buf;
	static char	*current_line[65535];

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = read(fd, buf, BUFFER_SIZE);
	if (size < 0)
		return (ft_for_norm(fd, &buf, current_line));
	while (size > 0)
	{
		buf[size] = '\0';
		if (!current_line[fd])
			current_line[fd] = ft_strdup(buf);
		else
			current_line[fd] = ft_strjoin(current_line[fd], buf, 0, -1);
		if (ft_strchr(current_line[fd], '\n'))
			break ;
		size = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_free(&buf), ft_extract_line_segment(&current_line[fd]));
}

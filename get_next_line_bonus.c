/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:03:55 by hlalouli          #+#    #+#             */
/*   Updated: 2021/12/09 17:05:13 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*new_line(char *hou)
{
	int		i;
	char	*line;

	i = 0;
	if (!hou)
		return (NULL);
	while (hou[i] && hou[i] != '\n')
		i++;
	line = ft_substr(hou, 0, i + 1);
	return (line);
}

int	line(char *hou)
{
	int	i;

	i = 0;
	if (!hou)
		return (0);
	while (hou[i])
	{
		if (hou[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*rest(char *hou)
{
	int		i;
	int		len;
	char	*line1;

	i = 0;
	if (!hou)
		return (NULL);
	len = ft_strlen(hou);
	while (hou[i] && hou[i] != '\n')
		i++;
	line1 = ft_substr(hou, i + 1, len - i + 1);
	free(hou);
	hou = NULL;
	return (line1);
}

char	*get_next_line(int fd)
{
	static char	*hou[1024];
	int			k;
	char		*new;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line(hou[fd]) == 1)
		return (new = new_line(hou[fd]), hou[fd] = rest(hou[fd]), new);
	k = read(fd, buff, BUFFER_SIZE);
	if (k <= 0)
	{
		if (!hou[fd])
			return (NULL);
		if (!*hou[fd])
			return (free(hou[fd]), hou[fd] = NULL, NULL);
		new = ft_strdup(hou[fd]);
		return (free(hou[fd]), hou[fd] = NULL, new);
	}
	buff[k] = 0;
	hou[fd] = ft_strjoin(hou[fd], buff);
	return (get_next_line(fd));
}

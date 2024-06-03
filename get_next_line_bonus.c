/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamhal <lamhal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 02:01:27 by lamhal            #+#    #+#             */
/*   Updated: 2024/01/09 17:13:58 by lamhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*tab[OPEN_MAX];
	char		*str;
	size_t		n;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (free(tab[fd]), tab[fd] = NULL);
	if (ft_strchr(tab[fd], '\n'))
		return (extractline(&tab[fd]));
	str = malloc((size_t)BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (!ft_strchr(str, '\n'))
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n == 0)
			break ;
		str[n] = 0;
		tab[fd] = ft_strjoin(tab[fd], str);
		if (!tab[fd])
			break ;
	}
	return (free(str), str = NULL, extractline(&tab[fd]));
}

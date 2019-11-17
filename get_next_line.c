/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:39:05 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/17 21:01:42 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <string.h>

#if defined BUFFER_SIZE

int	check(char *r_buffer)
{
	int i;

	i = 0;
	while (r_buffer[i])
	{
		if (r_buffer[i] == '\n')
			return (0);
		i++;
	}
	return(1);
}

int ft_free(char **p1, char **p2, int r_value)
{
	free(*p1);
	free(*p2);
	*p1 = NULL;
	*p2 = NULL;
	if (r_value != -98)
		return (r_value > 0 ? 1 : r_value);
	return (0);
}


int get_next_line(int fd, char **line)
{
	int			r_value;
	char		*r_buffer;
	char		*temp;
	static char *box;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) != 0
		|| !(r_buffer = malloc(BUFFER_SIZE * sizeof(char) + 1)))
		return(-1);
	if (!box)
		box = ft_strdup("");
	while (check(box) && (r_value = read(fd, r_buffer, BUFFER_SIZE)) > 0)	
	{
		r_buffer[r_value] = '\0';
		box = ft_strjoin(box, r_buffer);
	}
	if (!check(box))
	{
		*line = ft_substr(box, 0, s_strlen(box));
		temp = box;
		box = ft_strdup(box + s_strlen(box) + 1);
		ft_free(&temp, &r_buffer, -98);
		return (1);
	}
	*line = ft_strdup(box);
	return (ft_free(&r_buffer, &box, r_value));
}
/*
int    main(void)
{

	int i = open("normal.txt", O_RDONLY);
	char *line;
	int num = 1;

	while(num)
	{
		num = get_next_line(i, &line);
		printf( "(%d)===> %s\n" , num, line);
		free(line);
	}
	return (0);
}
*/
#endif

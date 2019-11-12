/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:39:05 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/12 18:09:13 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

#if defined BUFFER_SIZE

int get_next_line(int fd, char **line)
{	
	 static char *temp;
	int	r_value;

	r_value = 0;
	temp = malloc(BUFFER_SIZE + 1);
	*line = NULL;
	while ((r_value = read (fd, temp, 1)) > 0 && *temp != '\n')
		*line = ft_strjoin(*line, temp);
	
	if (r_value == 0)
		return (0);
	free (temp);
	return (1);
}
int    main(void)
{

	int i = open("txt.txt", O_RDONLY);
	char **line;
	int n , num = 0;

	n = 0;
	line = malloc (8 * 19);
	*line = malloc(BUFFER_SIZE);
	while (n++ < 21) 
	{
		 num = get_next_line(i, line);
		printf( "%d  %s\n" ,num, *line);
	}
	free(line);
	return (0);
}

#endif

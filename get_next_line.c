/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:39:05 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/16 21:34:36 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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

int	check_end(char *r_buffer)
{
	int i;

	i = 0;
	while (r_buffer[i])
	{
		if (r_buffer[i] == '\n' && r_buffer[i + 1] == '\0')
			return(0);
		i++;
	}
	return (1);
}

int	freedom(char *box, char *r_buffer)
{
	//free(box);
	box = NULL;
	//free(r_buffer);
	r_buffer = NULL;
	return (0);
	

}
int get_next_line(int fd, char **line)
{
	int			r_value;
	int			i;
	char		*r_buffer;
	char		*temp;
	static char *box;

	i = 1;
/*	if (!(*line = ft_strdup("")))
		return (-1);*/
	*line = NULL;
	if (BUFFER_SIZE < 0 || BUFFER_SIZE == 0)
		return(-1);	
	while (1)
	{
		if (box)
		{
			if (!check(box))
			{
				*line = ft_strjoin(*line, box);
				temp = ft_strdup(&box[ft_strchr(box, '\n') + 1]); 	
				free(box);
				box = temp;
				return (1);
			}
			else
			{	
				*line = ft_strdup(box);
				free(box);
				box = NULL;
			}
		}
		while (i) 
		{
			if (!(r_buffer = malloc(BUFFER_SIZE + 1 * sizeof(char))))
				return(-1);
			if ((r_value = read(fd, r_buffer, BUFFER_SIZE)) < 0)
				return (-1);
			r_buffer[r_value] = '\0';
			i = check(r_buffer);
			*line = ft_strjoin(*line, r_buffer);
			if (r_value == 0)
			{
				free(r_buffer);
				free(box);
				box = NULL;

				return (0);
				
			}
			if (i == 0)
				box = ft_strdup(&r_buffer[ft_strchr(r_buffer, '\n') + 1]);
		
		free(r_buffer);	
		}	
		return (1);
	}

}

/*
int    main(void)
{

	int i = open("txt.txt", O_RDONLY);
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

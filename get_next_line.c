/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:39:05 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/16 14:53:03 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

#if defined BUFFER_SIZE

int s_strlen(char *r_buffer)
{
	int size;

	size = 0;
	while (r_buffer[size] != '\n' && r_buffer[size] != '\0')
		size++;
	return(size);
}
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
	static char *box;

	i = 1;
	*line = ft_strdup("");
	if (BUFFER_SIZE < 0 || BUFFER_SIZE == 0)
		return(-1);	
	while (1)
	{
		if (box)
		{
			if (!check(box))
			{
				*line = ft_strjoin(*line, box);
				if ((&box[ft_strchr(box, '\n') + 1]))
					box = ft_strdup(&box[ft_strchr(box, '\n') + 1]); 	
				else
					free(box);
				return (1);
			}
			else
			{	
				*line = ft_strjoin(*line, box);
				free(box);
			}
		}
		while (i) 
		{	r_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
			if ((r_value = read(fd, r_buffer, BUFFER_SIZE)) < 0)
				return (-1);
			r_buffer[r_value] = '\0';
			i = check(r_buffer);
			*line = ft_strjoin(*line, r_buffer);
			if (r_value == 0)
			{
				free(box);
				box = NULL;
				return (0);
				
			}
			if (i == 0 && (&r_buffer[ft_strchr(r_buffer, '\n') + 1]))
				box = ft_strdup(&r_buffer[ft_strchr(r_buffer, '\n') + 1]);
		}
		free(r_buffer);	
		return (1);
	}

}


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

#endif

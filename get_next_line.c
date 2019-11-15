/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:39:05 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/15 22:01:55 by aymaatou         ###   ########.fr       */
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
	while (i < BUFFER_SIZE)
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
	*line = NULL;
	//static int st;	
	while (1)
	{
		
		if (box)
		{
			if (!check(box))
			{

			//printf("%d box %s\n", st++, box);	

				
				*line = ft_strjoin(*line, box);
				box = ft_strdup(&box[ft_strchr(box, '\n') + 1]); 	
				
			//	printf("box value: %s\n", box);
				return (1);
			}
			else
			{	
				*line = ft_strdup(box);
				free(box);
			}
		}


		
		while (i) 
		{	r_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
			r_value = read(fd, r_buffer, BUFFER_SIZE);
			r_buffer[r_value] = '\0';
			i = check(r_buffer);
			*line = ft_strjoin(*line, r_buffer);
			if (r_value == 0)
			{
				box = NULL;
			//	free(r_buffer);
			//	r_buffer = NULL;		
				return (freedom(box, r_buffer));
				
			}
			
			if (i == 0)
				box = ft_strdup(&r_buffer[ft_strchr(r_buffer, '\n') + 1]);
		}
		free(r_buffer);	
		return (1);
	}

}

int    main(void)
{

	int i = open("normal.txt", O_RDONLY);
	char *line;
	int n, num = 1;

	while(num)
	{
		num = get_next_line(i, &line);
		printf( "(%d)===> %s\n" , num, line);
		free(line);
	}
	return (0);
	
}

#endif

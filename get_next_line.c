/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:39:05 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/13 17:39:49 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

#if defined BUFFER_SIZE

int get_next_line(int fd, char **line)
{	
	static char *temp;
	static char *res;
	int	r_value, i = 0;

	r_value = 0;

	*line = NULL;
	if (res)
	{
		//printf("============>leftover : %s\n", res);
		while (res[i] != '\n' && res[i] != '\0')
			i++;

		//printf("aftre : %s\n", ft_substr(temp, 0, i));
		*line = ft_strjoin(*line, ft_substr(res,0, i));
		res = ft_strchr(res, '\n') + 1;
		/*if (res[i] == '\n')	
		{	puts("enter");*/
			return (1);
	//	}
	}
	temp = malloc(BUFFER_SIZE + 1);
	r_value = read (fd, temp, BUFFER_SIZE);
	if (r_value == 0)
		return (0);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
		printf("value temp \n%s\n", temp);
	//printf("aftre : %s\n", ft_substr(temp, 0, i));
	*line = ft_strjoin(*line, ft_substr(temp,0, i));
	//printf("line : %s\n", *line);
	res = ft_strchr(temp, '\n') + 1;
	//puts(temp);
	//free (temp);
	return (1);
}
int    main(void)
{

	int i = open("txt.txt", O_RDONLY);
	char *line;
	int n , num = 0;

	n = 0;
	line = malloc(BUFFER_SIZE + 1);
	while (n++ < 10) 
	{
		num = get_next_line(i, &line);
		printf( "(%d)==(%d)===> %s\n" ,n, num, line);
	}
	free(line);
	return (0);
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:39:05 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/14 15:38:14 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

#if defined BUFFER_SIZE

int b_check(char *temp)
{
	int i;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\n')
		return (0);
	else
		return (1);
}

/*void	res_check(char *res)
{
	if (res)
	{
		while (res[i] != '\n' && res[i] != '\0')
			i++;
		*line = ft_strjoin(*line, ft_substr(res,0, i));
		if (res[i] == '\n')
		{
			res = ft_strchr(res, '\n') + 1;
			return (1);
		}
	}
}*/

int get_next_line(int fd, char **line)
{	
	char *temp;
	static char *res;
	int	r_value;
	int	i;
   	int  stop;
   
	stop = 1;
	i = 0;
	r_value = 0;
	*line = NULL;
	temp = malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE == 0 || BUFFER_SIZE < 0)
		return (-1);
	if (res)
	{
		while (res[i] != '\n' && res[i] != '\0')
			i++;
		*line = ft_strjoin(*line, ft_substr(res,0, i));
		if (res[i] == '\n')
		{
			res = ft_strchr(res, '\n') + 1;
			if (res[0] == 0)
				return (0);
			return (1);
		}
	}

	while (stop)
	{
		if ((r_value = read (fd, temp, BUFFER_SIZE)) < 0)
			return (-1);
		temp[r_value] = '\0';	
		stop = b_check(temp);
		while (temp[i] != '\n' && temp[i] != '\0')
			i++;
		*line = ft_strjoin(*line, ft_substr(temp,0, i));
		if (r_value == 0)
			return (0);
	}
	res = ft_strdup("");
	res = ft_strchr(temp, '\n') + 1;
	free(temp);
	return (1);
}
int    main(void)
{

	int i = open("txt.txt", O_RDONLY);
	char *line;
	int n , num = 1;

	n = 1;
	line = malloc(BUFFER_SIZE + 1);
	while (num) 
	{
		num = get_next_line(i, &line);
		printf( "\n(%d)==(%d)===> %s\n" ,n, num, line);
		
		n++;
	}
	return (0);
}

#endif

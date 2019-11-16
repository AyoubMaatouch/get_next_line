#include "get_next_line.h"


int line_calculator(char *here)
{
	int i;

	i = 0;
	while (here[i])
	{
		if (here[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int check_line(char *here)
{
	int i;

	i = 0;
	while (here[i])
	{
		if (here[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_fill(char *from, char **to)
{
	int i;
	char *save;

	i = 0;
	*to = ft_strjoin(*to, from);
}


int	get_next_line(int fd, char **line)
{
	int r_value;
	int i;
	char *r_buffer;
	char *temp;
	static char *schrodinger;

	i = 0;	
	*line = NULL;
	while (1)
	{
		if (schrodinger)
		{
			if (check_line(schrodinger))
			{
				*line = ft_strjoin(*line, schrodinger);
				temp = ft_strdup(ft_strchr(schrodinger, '\n'));
				free(schrodinger);
				schrodinger = temp;
				return (1);
			}
			else
			{
				*line = ft_strdup(schrodinger);
				free(schrodinger);
			}
		}
		r_buffer = malloc(sizeof(char) + BUFFER_SIZE + 1);
		r_value = read(fd, r_buffer, BUFFER_SIZE);
		r_buffer[r_value] = '\0';
		ft_fill(r_buffer, line);
	if (check_line(r_buffer) == 1)
	{ 
		i = line_calculator(r_buffer);
		schrodinger = ft_strdup(ft_strchr(r_buffer, '\n'));
		free(r_buffer);
		return (1);
	}
	}
}

int    main(void)
{
	int fd = open("txt.txt", O_RDONLY);
	char *line;
	int n = 0;

	while ( n < 20)
	{
		get_next_line(fd, &line);
		puts(line);
		free(line);
		n++;
	}
	return(0);
}


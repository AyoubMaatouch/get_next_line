nclude "get_next_line.h"

#if defined BUFFER_SIZE

int get_next_line(int fd, char **line)
{	
	char *temp;
	static char *res;
	int	r_value, i = 0;
	static int find;
	r_value = 0;

	*line = NULL;
	//puts(res);
	//	if (res)
	//		{
	//			//	printf ("res %d \n %s", find++, res);
	//					//printf("============>leftover : %s\n", res);
	//							while (res[i] != '\n' && res[i] != '\0')
	//										i++;
	//
	//												//printf("aftre : %s\n", ft_substr(temp, 0, i));
	//														*line = ft_strjoin(*line, ft_substr(res,0, i));
	//																//printf("line  %s\n", *line);
	//																		//puts(res);
	//																				if (res[i] == '\n')
	//																						{
	//																									res = ft_strchr(res, '\n') + 1;
	//																												return (1);
	//																														}
	//																															}
	//																																temp = malloc(BUFFER_SIZE + 1);
	//																																	r_value = read (fd, temp, BUFFER_SIZE);
	//																																		if (r_value == 0)
	//																																			{	*line = NULL;
	//																																					return (0);
	//																																						}
	//																																							while (temp[i] != '\n' && temp[i] != '\0')
	//																																									i++;
	//																																										*line = ft_strjoin(*line, ft_substr(temp,0, i));
	//																																											res = ft_strchr(temp, '\n') + 1;
	//																																												//free (temp);
	//																																													return (1);
	//																																													}
	//																																													int    int    main(void)
	//																																													{
	//																																													return (0);
	//																																													}(void)
	//																																													{
	//
	//																																														int i = open("txt.txt", O_RDONLY);
	//																																															char *line;
	//																																																int n , num = 0;
	//
	//																																																	n = 0;
	//																																																		line = malloc(BUFFER_SIZE + 1);
	//																																																			while (n++ < 25) 
	//																																																				{
	//																																																						num = get_next_line(i, &line);
	//																																																								printf( "\n(%d)==(%d)===> %s\n" ,n, num, line);
	//																																																									}
	//																																																										return (0);
	//																																																										}
	//
	//																																																										#endif

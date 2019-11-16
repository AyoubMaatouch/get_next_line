/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:46:33 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/16 18:54:00 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:13:19 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/16 17:30:03 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int s_strlen(char *r_buffer)
{
	int size;

	size = 0;
	while (r_buffer[size] != '\n' && r_buffer[size] != '\0')
		size++;
	return(size);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		f_len;	

	i = 0;
	if (s1 == NULL)
		f_len = 0;
	else
		f_len = s_strlen(s1);
	if (!(str = (char *)malloc((f_len + s_strlen(s2)) * sizeof(char) + 1)))
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free(s1);
	}

	while (s_strlen(s2))
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = 0;
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str[i] == '\0')
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char*)&str[i + 1]);
		i++;
	}
	return (NULL);
}
*/
int	ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}
char	*ft_strdup(char *s1)
{
	char	*r_value;
	int		i;

	i = 0;
	if (!(r_value = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1)))
		return (NULL);
	while (s1[i])
	{
		r_value[i] = s1[i];
		i++;
	}
	r_value[i] = 0;
	return (r_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:13:19 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/18 11:35:52 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		s_strlen(char *r_buffer)
{
	int size;

	size = 0;
	while (r_buffer[size])
		if (r_buffer[size] == '\n')
			return (size);
		else
			size++;
	return (0);
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
		f_len = ft_strlen(s1);
	if (!(str = (char *)malloc((f_len + ft_strlen(s2)) * sizeof(char) + 1)))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	if (s1)
		free(s1);
	while (ft_strlen(s2))
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = 0;
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*r_value;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(r_value = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1)))
		return (NULL);
	while (s1[i])
	{
		r_value[i] = s1[i];
		i++;
	}
	r_value[i] = '\0';
	return (r_value);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	if (!(ptr = (char *)malloc((len * sizeof(char)) + 1)))
		return (NULL);
	while (len && s[j])
	{
		ptr[i++] = s[start + j++];
		len--;
	}
	ptr[i] = 0;
	return (ptr);
}

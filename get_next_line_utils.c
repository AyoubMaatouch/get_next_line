/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:13:19 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/14 14:45:19 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		f_len;	

	i = 0;
	if (s1 == NULL)
		f_len = ft_strlen(s2);
	else
		f_len = ft_strlen(s1);
	if (!(str = (char *)malloc((f_len +
						ft_strlen(s2)) * sizeof(char) + 1)))
		return (NULL);
	if (s1)
	{
		while (ft_strlen(s1))
		{
			str[i] = *s1;
			s1++;
			i++;
		}
	}
	while (ft_strlen(s2))
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
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char*)str);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

char	*ft_strdup(const char *s1)
{
	char	*r_value;
	int		i;

	i = 0;
	if (!(r_value = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1)))
		return (NULL);
	while (ft_strlen(s1))
	{
		r_value[i] = *s1++;
		i++;
	}
	r_value[i] = 0;
	return (r_value);
}

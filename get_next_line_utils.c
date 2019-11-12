/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:13:19 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/12 18:04:42 by aymaatou         ###   ########.fr       */
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
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[0]);
		i++;
	}
	if (c == '\0')
		return ((char*)&str[0]);
	return ((char*)str);
}

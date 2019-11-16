/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:17:28 by aymaatou          #+#    #+#             */
/*   Updated: 2019/11/16 18:50:41 by aymaatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int s_strlen(char *r_buffer);
char	*ft_strjoin(char *s1 ,char *s2);
char	*ft_strjoin_box(char *s1 ,char *s2);
size_t	ft_strlen(const char *str);
//char	*ft_strchr(const char *str, int c);
int		ft_strchr(const char *str, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
int get_next_line(int fd, char **line);

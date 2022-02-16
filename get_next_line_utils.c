/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 05:23:38 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/02/16 18:14:54 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;
	char	*cpy;

	if (!s)
		return (0);
	cpy = (char *)s;
	idx = 0;
	while (cpy[idx])
		idx++;
	return (idx);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		++str;
	}
	return (str);
}

void	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;

	idx = 0;
	while (src[idx] && idx + 1 < size)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = 0;
}

void	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	while (*src && dst_len + 1 < size)
	{
		dst[dst_len] = *src;
		src++;
		dst_len++;
	}
	dst[dst_len] = *src;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	if (!s2)
	{
		free(s1);
		return (0);
	}
	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
	{
		free(s1);
		return (0);
	}
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	ft_strlcat(ret, s2, ft_strlen(ret) + ft_strlen(s2) + 1);
	free (s1);
	return (ret);
}

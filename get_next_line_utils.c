/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoraes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:19:38 by gamoraes          #+#    #+#             */
/*   Updated: 2024/02/05 02:34:09 by gamoraes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t	count;

	count = 0;
	while (*string++)
		count++;
	return (count);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*strdup;

	len = ft_strlen(s);
	strdup = (char *)malloc((len + 1) * sizeof(char));
	if (!strdup)
		return (NULL);
	strdup = ft_strcpy(strdup, s);
	return (strdup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*strjoin;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	strjoin = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	while (s1[i])
		strjoin[i++] = s1[j++];
	j = 0;
	while (s2[j])
		strjoin[i++] = s2[j++];
	strjoin[i] = '\0';
	return (strjoin);
}

char	*ft_substr(char const *s, unsigned int start, size_t length)
{
	size_t	size;
	size_t	substrlen;
	char	*substr;

	size = ft_strlen(s);
	substrlen = size - (size_t) start;
	if (!s)
		return (NULL);
	if (start > size)
		return ((char *)malloc(1 * sizeof(char)));
	if (length > size)
		length = (size - start) + 1;
	if (substrlen > length)
		substrlen = length;
	substr = (char *)malloc((substrlen + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strcpy(substr, (s + start));
	return (substr);
}

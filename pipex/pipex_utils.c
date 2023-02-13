/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:47:26 by cpollito          #+#    #+#             */
/*   Updated: 2022/02/24 14:08:34 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((s11[i] != s22[i] && s11[i] > s22[i]))
			return (s11[i] - s22[i]);
		if (s11[i] != s22[i] && s11[i] < s22[i])
			return (s11[i] - s22[i]);
		if (!s11[i] || !s22[i])
			return (0);
		i++;
	}
	return (0);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	char	*s12;
	char	*cs1;
	char	*cs2;
	int		i;

	i = 0;
	cs1 = (char *)s1;
	cs2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	s12 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s12)
		return (NULL);
	while (*cs1)
		s12[i++] = *cs1++;
	while (*cs2)
		s12[i++] = *cs2++;
	s12[i] = '\0';
	return (s12);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

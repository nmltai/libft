/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 23:06:08 by ntai              #+#    #+#             */
/*   Updated: 2018/04/07 23:02:59 by ntai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_traverse_f(char const *s)
{
	while ((*s == '\n' || *s == ' ' || *s == '\t') && *s != '\0')
		++s;
	return ((char *)s);
}

static	char	*ft_traverse_b(char const *s)
{
	while (*s)
		++s;
	s -= 1;
	while (*s == '\n' || *s == ' ' || *s == '\t')
		s -= 1;
	return ((char *)s);
}

static	int		ft_counter(char *s1, char *s2)
{
	int n;

	n = 0;
	while (s1 != s2)
	{
		++s1;
		++n;
	}
	return (n);
}

char			*ft_strtrim(char const *s)
{
	char	*new_string;
	char	*tracker;
	char	*tracker2;
	char	*place_hold;
	int		new_string_length;

	new_string_length = 0;
	tracker = ft_traverse_f(s);
	if (*tracker == '\0')
		return ("");
	tracker2 = ft_traverse_b(s);
	new_string_length = ft_counter(tracker, tracker2);
	new_string_length++;
	new_string = (char *)malloc(new_string_length + 1);
	if (new_string == NULL)
		return (NULL);
	place_hold = new_string;
	tracker = ft_traverse_f(s);
	while (new_string_length--)
		*new_string++ = *tracker++;
	*new_string = '\0';
	return (place_hold);
}

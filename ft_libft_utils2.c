/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:05:08 by amessah           #+#    #+#             */
/*   Updated: 2022/03/21 17:05:50 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	a;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((a + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (s1 && s2)
	{
		while (s1[i])
			str[k++] = s1[i++];
		while (s2[j])
			str[k++] = s2[j++];
		str[k] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_strcon(int con, long n2, char *str)
{
	int	neg;

	neg = 0;
	if (n2 < 0)
	{
		n2 = n2 * (-1);
		neg = 1;
	}
	while (con >= 0)
	{
		str[con] = n2 % 10 + '0';
		n2 = n2 / 10;
		con--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

static int	ft_num(long n2)
{
	int	con;

	con = 0;
	if (n2 < 0)
	{
		n2 = n2 * (-1);
		con++;
	}
	while (n2 > 9)
	{
		n2 = n2 / 10;
		con++;
	}
	con++;
	return (con);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		con;
	int		sign;

	sign = 0;
	con = ft_num(n);
	str = (char *)malloc((con + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	str[con] = '\0';
	con--;
	return (ft_strcon(con, n, str));
}

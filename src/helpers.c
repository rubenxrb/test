/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:27:37 by rromero           #+#    #+#             */
/*   Updated: 2017/02/10 20:27:38 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

const char	*skip_fmt(const char *s)
{
	while (!isspecifier(*s))
		s++;
	return (s + 1);
}

char		ismodif(char c)
{
	char	valid[8];
	char	*p;

	ft_bzero(valid, 8);
	ft_strcpy(valid, "hlLjzZt");
	p = valid;
	while (*p)
		if (c == *p++)
			return (c);
	return (0);
}

char		isspecifier(char c)
{
	char	valid[28];
	char	*p;

	ft_bzero(valid, 28);
	ft_strcpy(valid, "sSpdDioOuUxXcCeEfFgGaAn%~kr");
	p = valid;
	while (*p)
		if (c == *p++)
			return (c);
	return (0);
}

char		isflag(char c)
{
	char	valid[7];
	char	*p;

	ft_bzero(valid, 7);
	ft_strcpy(valid, "-0+# $");
	p = valid;
	while (p && *p)
		if (c == *p++)
			return (c);
	return (0);
}

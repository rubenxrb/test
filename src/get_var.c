/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:27:37 by rromero           #+#    #+#             */
/*   Updated: 2017/02/10 20:27:38 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*get_format(const char *fmt)
{
	char	*ret;
	char	*p;
	size_t	size;

	p = (char *)fmt;
	size = (p ? 1 : 0);
	while (!isspecifier(*p))
	{
		p++;
		size++;
	}
	ret = ft_strnew(size);
	ret = ft_strncpy(ret, fmt, size);
	return (ret);
}

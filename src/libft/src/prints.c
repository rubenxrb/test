/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:16:18 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:16:19 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putchar(const char ch)
{
	return (write(1, &ch, 1));
}

size_t	ft_putchar_fd(const char ch, int fd)
{
	return (write(fd, &ch, 1));
}

size_t	ft_putstr(const char *s)
{
	return (write(1, s, ft_strlen(s)));
}

size_t	ft_putstr_fd(char const *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

size_t	ft_putnstr_fd(const char *s, size_t len, int fd)
{
	return (write(fd, s, len));
}

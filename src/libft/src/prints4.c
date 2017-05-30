/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 01:38:05 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 01:38:05 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	putcstr(char const *s, size_t col)
{
	size_t	ln;

	set_color(col);
	ln = ft_putstr(s);
	set_color(0);
	return (ln);
}

size_t	putcnstr(char const *s, size_t len, size_t col)
{
	size_t	ln;

	set_color(col);
	ln = ft_putnstr_fd(s, len, 1);
	set_color(0);
	return (ln);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:43:02 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:42:30 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long n, int b)
{
	char	*num;
	size_t	len;
	long	mod;

	len = ft_ulnumlen(n, b);
	num = ft_strnew(len);
	while (len--)
	{
		mod = n % b;
		num[len] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}

char	escape_seq(char seq[2])
{
	if (!ft_strncmp(seq, "\\'", 2))
		return (0x27);
	else if (!ft_strncmp(seq, "\\", 2))
		return (0x5c);
	else if (!ft_strncmp(seq, "\\\"", 2))
		return (0x22);
	else if (!ft_strncmp(seq, "\\n", 2))
		return (0x0a);
	else if (!ft_strncmp(seq, "\\r", 2))
		return (0x0d);
	else if (!ft_strncmp(seq, "\\b", 2))
		return (0x08);
	else if (!ft_strncmp(seq, "\\t", 2))
		return (0x09);
	else if (!ft_strncmp(seq, "\\f", 2))
		return (0x0c);
	else if (!ft_strncmp(seq, "\\a", 2))
		return (0x07);
	else if (!ft_strncmp(seq, "\\v", 2))
		return (0x0b);
	return (0);
}

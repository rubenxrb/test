/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:42:29 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:42:30 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hextoa(long long n, size_t prec)
{
	char	*tmp;
	char	*num;
	char	*hex;

	num = ft_lltoa_base(n, 16);
	hex = num;
	if (prec)
	{
		tmp = ft_strnew(prec);
		ft_memset(tmp, '0', prec);
		hex = ft_strinsrt(num, 0, tmp);
		ft_strdel(&tmp);
	}
	hex = ft_strinsrt(num, 0, "0x");
	ft_strdel(&num);
	return (hex);
}

int		uctoutf8(const char *dest, wchar_t ch)
{
	unsigned char	*p;

	p = (unsigned char *)dest;
	if (ch < 0x80)
		*p++ = (unsigned char)(ch);
	else if (ch < 0x800)
	{
		*p++ = (unsigned char)((ch >> 6) | 0xC0);
		*p++ = (unsigned char)((ch & 0x3F) | 0x80);
	}
	else if (ch < 0x10000)
	{
		*p++ = (unsigned char)(((ch >> 12)) | 0xE0);
		*p++ = (unsigned char)(((ch >> 6) & 0x3F) | 0x80);
		*p++ = (unsigned char)((ch & 0x3F) | 0x80);
	}
	else if (ch < 0x110000)
	{
		*p++ = (unsigned char)(((ch >> 18)) | 0xF0);
		*p++ = (unsigned char)(((ch >> 12) & 0x3F) | 0x80);
		*p++ = (unsigned char)(((ch >> 6) & 0x3F) | 0x80);
		*p++ = (unsigned char)((ch & 0x3F) | 0x80);
	}
	return ((void *)p == (void *)dest);
}

int		ft_hextoi(const char *hex)
{
	t_byte	hex_p;
	int		ret;

	if (!hex)
		return (0);
	ret = 0;
	while (*hex)
	{
		hex_p = *hex++;
		if (hex_p >= '0' && hex_p <= '9')
			hex_p = hex_p - '0';
		else if (hex_p >= 'a' && hex_p <= 'f')
			hex_p = hex_p - 'a' + 10;
		else if (hex_p >= 'A' && hex_p <= 'F')
			hex_p = hex_p - 'A' + 10;
		ret = (ret << 4) | (hex_p & 0xF);
	}
	return (ret);
}

char	*ft_lltoa_base(long long n, int b)
{
	char		*num;
	size_t		size;
	int			neg;
	long		mod;

	neg = 0;
	size = ft_lnumlen(n, b);
	if (n < 0 && b == 10)
		neg++;
	num = ft_strnew(size);
	if (neg)
		num[0] = '-';
	num[size + neg] = 0;
	while (size--)
	{
		mod = ((n % b) < 0 ? -(n % b) : (n % b));
		num[size + neg] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}

char	*ft_uitoa_base(unsigned int n, int b)
{
	char	*num;
	size_t	len;
	size_t	mod;

	len = ft_unumlen(n, b);
	num = ft_strnew(len);
	while (len--)
	{
		mod = n % b;
		num[len] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:27:37 by rromero           #+#    #+#             */
/*   Updated: 2017/02/10 20:27:38 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_array		*make_str(t_agv *fmt, va_list *ap)
{
	t_array	*str;
	char	*agv;
	int		len;
	char	*sp;

	agv = printfstrdup(va_arg(*ap, char *));
	sp = fmt->flgs ? fmt->flgs : 0;
	if ((sp) && *sp == '-')
		sp++;
	if (fmt->prec < (int)ft_strlen(agv) && fmt->prec > 0)
		*(agv + fmt->prec) = 0;
	len = ft_strlen(agv);
	str = array_new(1, (fmt->width > fmt->prec ? fmt->width : len) + 1);
	str->bytes = str->len - 1;
	ft_strcpy(str->data, agv);
	if (fmt->width > fmt->prec)
	{
		ft_memset(str->data, sp && *sp == '0' ? *sp : ' ', str->bytes);
		if (ft_strchr(fmt->flgs, '-'))
			ft_strncpy(str->data, agv, len);
		else
			ft_strncpy(str->data + (str->bytes - len), agv, len);
	}
	ft_strdel(&agv);
	return (str);
}

t_array		*make_wstr(va_list *ap)
{
	t_array	*str;
	wchar_t	*agv;
	size_t	len;

	agv = wstrdup(va_arg(*ap, wchar_t *));
	if (!agv)
		return (0);
	len = wstrlen(agv);
	str = array_new(sizeof(wchar_t), len);
	ft_memcpy(str->data, agv, str->bytes);
	ft_memdel((void **)&agv);
	return (str);
}

t_array		*make_cstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return (array_new(sizeof(char), 1));
}

t_array		*make_cwstr(t_agv *fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return (array_new(sizeof(wchar_t), 1));
}

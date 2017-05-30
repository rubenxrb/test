/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_decimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:27:37 by rromero           #+#    #+#             */
/*   Updated: 2017/02/10 20:27:38 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_array		*make_decimal(t_agv *fmt, char type, t_byte caps, va_list *ap)
{
	(void)fmt;
	(void)type;
	(void)ap;
	(void)caps;
	return (array_new(sizeof(char), 1));
}

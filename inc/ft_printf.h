/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:49:41 by rromero           #+#    #+#             */
/*   Updated: 2017/01/31 23:41:53 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include "libft.h"

# define SUM_SIZE(d_size) (d_size == 1 ? current->bytes : current->len)
# define ISNEG(num) (num < 0 ? 1 : 0)

typedef struct	s_agv
{
	char		*flgs;
	int			width;
	int			prec;
	char		*l_mod;
	char		type;
	size_t		base;
	int			param;
}				t_agv;

int				ft_printf(const char *s, ...);
int				printf_fd(const int fd, const char *s, ...);
int				printf_str(void **dest, const char *s, ...);
t_lst			*printf_lst(const char *s, ...);
t_lst			*listof_vars(const char *s, va_list ap);
char			*get_format(const char *_format);
size_t			set_flags(t_agv *ret, char *fmt);
size_t			set_minwidth(t_agv *ret, const char *fmt);
size_t			set_prec(t_agv *ret, const char *fmt);
size_t			set_lmod(t_agv *ret, const char *fmt);
size_t			set_base(const char spec);
size_t			print_var(t_node **node, const int fd, const char nxt);
const char		*skip_fmt(const char *s);
char			isspecifier(char c);
char			isflag(char c);
char			ismodif(char c);
t_array			*make_str(t_agv *fmt, va_list *ap);
t_array			*make_wstr(va_list *ap);
t_array			*make_cstr(t_agv *fmt, va_list *ap);
t_array			*make_cwstr(t_agv *fmt, va_list *ap);
t_array			*make_signed(t_agv *fmt, char type, va_list *ap);
t_array			*make_uint(t_agv *fmt, char *lmod, va_list *ap);
t_array			*make_fhex(t_agv *fmt, char c, va_list *ap);
t_array			*make_hex(t_agv *fmt, char c, va_list *ap);
t_array			*make_decimal(t_agv *fmt, char type, t_byte caps, va_list *ap);
t_array			*make_utils(t_agv *fmt, char type, va_list *ap);
void			uint_prefix(t_array **hex, char type);

#endif

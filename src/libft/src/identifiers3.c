/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 00:56:21 by rromero           #+#    #+#             */
/*   Updated: 2017/03/05 00:49:07 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isletter(char c1, char c2)
{
	return (ft_tolower(c1) == ft_tolower(c2));
}

int		isescapeseq(char *seq, size_t s_len)
{
	if (!ft_strncmp(seq, "\'", s_len))
		return (1);
	else if (!ft_strncmp(seq, "\\", s_len))
		return (1);
	else if (!ft_strncmp(seq, "\"", s_len))
		return (1);
	else if (!ft_strncmp(seq, "\n", s_len))
		return (1);
	else if (!ft_strncmp(seq, "\r", s_len))
		return (1);
	else if (!ft_strncmp(seq, "\b", s_len))
		return (1);
	else if (!ft_strncmp(seq, "\t", s_len))
		return (1);
	else if (!ft_strncmp(seq, "\f", s_len))
		return (1);
	else if (!ft_strncmp(seq, "\a", s_len))
		return (1);
	else if (!ft_strncmp(seq, "\v", s_len))
		return (1);
	return (0);
}
